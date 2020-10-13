source coatlUcd_propertyTypes.tcl

set doParse 0; # True for parsing UCD, false for reading pre-parsed result
set doSave 1; # True for saving UCD parsing result

set srcroot "../../src"
set includeroot "../../include"
set reroot "../../src/re"

###############################################################################
#
# Property types.
#
###############################################################################

set f [open coatlUcdProperties.tmpl.h]
unset -nocomplain templates; array set templates [read $f]
close $f

set out [open [file join $includeroot coatlUcdProperties.h] w]
fconfigure $out -buffering line

puts $out [subst -nobackslashes -nocommands $templates(header)]

puts $out [subst -nobackslashes -nocommands $templates(ucdPropertiesGroup)]

#
# Parse PropertyAliases.txt and generate enum values for property names.
#

set propertyAliases [dict create]

set f [open ucd/PropertyAliases.txt]
fconfigure $f -buffering line
while {![eof $f]} {
    set line [string trim [gets $f]]
    
    # Skip blank lines.
    if {$line eq ""} continue
    
    # Skip comments.
    if {[regexp {^#(.*)} $line all comment]} continue
    
    # Semicolon-separated list of property aliases.
    set split [split $line ";"]
    set aliases [list]
    foreach alias $split {
        lappend aliases [string trim $alias]
    }
    foreach alias $aliases {
        dict set propertyAliases $alias $aliases
    }
}
close $f

# Generate comments & code.

set values ""
set comments ""
set number 0
dict for {property info} $properties {
    if {[dict get $info type] eq "deprecated"} continue
    
    incr number

    set Property [string totitle $property 0 0]
    set PROPERTY [string toupper $property]

    set aliases [list]
    set ALIASES [list]
    foreach alias [dict get $propertyAliases $property] {
        set ALIAS [string toupper $alias]
        lappend aliases [subst -nobackslashes -nocommands $templates(propertyAlias)]
        if {$ALIAS ni $ALIASES} {lappend ALIASES $ALIAS}
    }
    set aliases [join $aliases ", "]
    append values [subst -nobackslashes -nocommands $templates(propertiesEnumValue)]
    append comments [subst -nobackslashes -nocommands $templates(propertiesEnumValueComment)]
    foreach ALIAS $ALIASES {
        if {$ALIAS eq $PROPERTY} continue
        append values [subst -nobackslashes -nocommands $templates(propertiesEnumAlias)]
        append comments [subst -nobackslashes -nocommands $templates(propertiesEnumAliasComment)]
    }
}
puts $out [subst -nobackslashes -nocommands $templates(propertiesEnum)]


#
# Parse PropertyValueAliases.txt and generate values for enumerated properties.
#

set f [open ucd/PropertyValueAliases.txt]
fconfigure $f -buffering line
while {![eof $f]} {
    set line [gets $f]
    
    # Trailing comment.
    unset -nocomplain comment
    regexp {([^#]*)#(.*)} $line all line comment

    set line [string trim $line]

    # Skip blank lines.
    if {$line eq ""} continue

    # Semicolon-separated list.
    set split [split $line ";"]
    
    # First one is property name.
    set property [string trim [lindex $split 0]]
    
    # Skip unknown & non-enum properties.
    if {![dict exists $properties $property] || [dict get $properties $property type] ne "enum"} continue
    
    if {$property eq "gc" && [info exists comment]} {
        # Special case: don't define OR-ed General Category values (e.g. 
        # L/Letter = Ll | Lm | Lo | Lt | Lu).
        continue
    }
    
    # Remainder are value aliases.
    set aliases [list]
    foreach alias [lreplace $split 0 0] {
        set alias [string trim $alias]
        if {$alias ni $aliases} {
            lappend aliases $alias
        }
    }
    if {[dict exists $properties $property values]} {
        set values [dict get $properties $property values]
    } else {
        set values [list]
    }
    lappend values $aliases
    dict set properties $property values $values
}
close $f

# Generate comments & code.

set values ""
set comments ""
dict for {property info} $properties {
    if {[dict get $info type] ne "enum"} continue

    set Property [string totitle $property 0 0]
    set PROPERTY [string toupper $property]
    set padding [string repeat " " [expr {9-[string length $property]}]]

    set number 0
    set values ""
    set comments ""
    foreach v [dict get $info values] {
        incr number

        set aliases [list]
        set ALIASES [list]
        foreach alias $v {
            # Replace dots and minus by underscore as well (cf. 'age' and 'blk' 
            # properties).
            set ALIAS [string toupper [string map {. _ - _} $alias]]
            lappend aliases [subst -nobackslashes -nocommands $templates(propertyValueAlias)]
            if {$ALIAS ni $ALIASES} {lappend ALIASES $ALIAS}
        }
        set value [lindex $aliases 0]
        set VALUE [lindex $ALIASES 0]
        set aliases [join $aliases ", "]
        append values [subst -nobackslashes -nocommands $templates(propertyEnumValue)]
        append comments [subst -nobackslashes -nocommands $templates(propertyEnumValueComment)]
        foreach ALIAS $ALIASES {
            if {$ALIAS eq $VALUE} continue
            append values [subst -nobackslashes -nocommands $templates(propertyEnumAlias)]
            append comments [subst -nobackslashes -nocommands $templates(propertyEnumAliasComment)]
        }
    }
    puts $out [subst -nobackslashes -nocommands $templates(propertyEnum)]
}
    

puts $out [subst -nobackslashes -nocommands $templates(footer)]


###############################################################################
#
# Property data & accessors.
#
###############################################################################

set f [open coatlUcd.tmpl.h]

unset -nocomplain templates; array set templates [read $f]
close $f

set out [open [file join $includeroot coatlUcd.h] w]
fconfigure $out -buffering line

puts $out [subst -nobackslashes -nocommands $templates(header)]

#
# Generate accessor declarations for all known properties.
#

set declarations ""
set nb 0
dict for {property info} $properties {
    if {[dict get $info type] in {deprecated name}} continue

    set Property [string totitle $property 0 0]
    set PROPERTY [string toupper $property]

    if {$nb == 0} {
        append declarations [subst -nobackslashes -nocommands $templates(propertyAccessorDeclarationFirst)]
    } elseif {($nb % 2) == 0} {
        append declarations [subst -nobackslashes -nocommands $templates(propertyAccessorDeclarationWrap)]
    } else {
        append declarations [subst -nobackslashes -nocommands $templates(propertyAccessorDeclarationNext)]
    }
    incr nb
}
puts $out [subst -nobackslashes -nocommands $templates(ucdPropertyAccessorsGroup)]

dict for {property info} $properties {
    if {[dict get $info type] in {deprecated name}} continue

    set Property [string totitle $property 0 0]
    set PROPERTY [string toupper $property]
    set padding [string repeat " " [expr {6-[string length $property]}]]

    set type [dict get $info type]
    if {$type eq "enumList"} {
        set elementProperty [dict get $info enumType]
        set ElementProperty [string totitle $elementProperty 0 0]
        set ELEMENT_PROPERTY [string toupper $elementProperty]
        
        set nbValues [llength [dict get $properties $elementProperty values]]
        set valueType [expr {$nbValues<256?"char":$nbValues<65536?"short":"int"}]
        puts $out [subst -nobackslashes -nocommands $templates(propertyAccessor_$type)]
    } else {
        puts $out [subst -nobackslashes -nocommands $templates(propertyAccessor_$type)]
    }
}

#
# Generate accessor macros for all known property aliases.
#

dict for {property info} $properties {
    if {[dict get $info type] in {deprecated name}} continue

    set Property [string totitle $property 0 0]
    set PROPERTY [string toupper $property]

    set Aliases [list]
    foreach alias [dict get $propertyAliases $property] {
        set Alias [string totitle $alias 0 0]
        if {$alias eq $property || $Alias eq $Property || $Alias in $Aliases} continue
        lappend Aliases $Alias
        set ALIAS [string toupper $alias]
        switch $type {
            mcp -
            enumList {
                puts $out [subst -nobackslashes -nocommands $templates(propertyAccessorAliasList)]
            }
            default {
                puts $out [subst -nobackslashes -nocommands $templates(propertyAccessorAlias)]
            }
        }
    }
}

puts $out [subst -nobackslashes -nocommands $templates(footer)]

close $out



set f [open coatlUcd.tmpl.c]
unset -nocomplain templates; array set templates [read $f]
close $f

set out [open [file join $srcroot coatlUcd.c] w]
fconfigure $out -buffering line

puts $out [subst -nobackslashes -nocommands $templates(header)]

puts $out [subst -nobackslashes -nocommands $templates(ucdCompiledDataGroup)]

if {$doParse} {
    puts "Parsing..."
    puts -nonewline "  Parsing XML..."; flush stdout
    # Parse the grouped XML database as it is much faster & less memory intensive 
    # than the flat version.
    package require tdom
    set f [open ucdxml/ucd.all.grouped.xml]
    dom parse -channel $f ucd
    close $f
    puts " Done"
    $ucd selectNodesNamespaces {ucd "http://www.unicode.org/ns/2003/ucd/1.0"}


    puts "Building data..."
    array set propertyValues {}
    array set lastValue {}
    set lastCp 0
    # Iterate over groups then over their child nodes.
    set groups [$ucd selectNodes {//ucd:group}]
    set nbgroups [llength $groups]
    set igroup 0
    foreach group $groups {
        puts "  Group [incr igroup]/$nbgroups"

        # Get group property values.
        set groupAttributes [dict create]
        foreach property [$group attributes] {
            if {[dict exists $properties $property] && [dict get $properties $property type] ni {deprecated name}} {
                dict set groupAttributes $property [$group @$property]
            }
        }

        foreach child [$group childNodes] {
            # Get property values by merging child & group properties.
            set attributes $groupAttributes
            foreach property [$child attributes] {
                if {[dict exists $properties $property] && [dict get $properties $property type] ni {deprecated name}} {
                    dict set attributes $property [$child @$property]
                }
            }
            
            # Build value ranges.
            dict for {property value} $attributes {
                # Get first codepoint in range.
                if {[$child hasAttribute cp]} {
                    set cp 0x[$child @cp]
                    set lastCp $cp
                } else {
                    set cp 0x[$child @first-cp]
                    set lastCp 0x[$child @last-cp]
                }

                # Type-specific value handling.
                switch [dict get $properties $property type] {
                    cp {
                        # Single-codepoint property.
                        if {$value eq "" || $value eq "#"} {
                            # Empty or hash map to zero.
                            set value 0
                        } else {
                            # Use offset.
                            set value 0x$value
                            incr value -$cp
                        }
                    }
                    mcp {
                        # Multiple-codepoint property.
                        if {$value eq "" || $value eq "#"} {
                            # Empty or hash map to zero.
                            set value 0
                        } elseif {[llength $value] == 1} {
                            # Use offset.
                            set value 0x[lindex $value 0]
                            incr value -$cp
                        } else {
                            # Use list of codepoints.
                            set lv [list]
                            foreach v $value {
                                lappend lv 0x$v
                            }
                            set value $lv
                        }
                    }
                }
                
                # If value changed, this marks the beginning of a new range.
                # Assume the XML database always use the abbreviated name, i.e. the 
                # second field in the PropertyValueAliases.txt file, so that we can
                # safely compare values.
                if {![info exists lastValue($property)] || $lastValue($property) ne $value} {
                    lappend propertyValues($property) $cp $value
                    set lastValue($property) $value
                }
            }
        }
    }
    if {$doSave} {
        puts -nonewline "Saving data..."; flush stdout
        set data [open coatlUcd.data w]
        puts $data "array set propertyValues {"
        foreach {key value} [array get propertyValues] {
            puts $data "\t${key} [list $value]"
        }	
        puts $data "}"
        puts $data "set lastCp $lastCp"
        close $data
        puts " Done"
    }
    puts "Done parsing"
} else {
    source coatlUcd.data
}

# At this point we have per-property ranges of values, now output C file.
# For each property we output two C arrays:
#
#  - First one is used for indexing; it gives the first codepoint in a 
#    contiguous range of values (omitting the first entry which is always zero).
#    This array is binary-searched during lookup until we find the range 
#    containing a given codepoint.
#  - Second one is used for values. The index computed during lookup in the 
#    first array gives the index in this second array (1 is added for the 
#    missing first entry).
#  - If the value type is enumerated, values are directly stored in the second
#    array. Otherwise, the latter stores an index to a third array containing
#    the set of unique values. This can be a C string or the first element in
#    a list (usually zero-terminated, depending on the type).
#
# The code always choose the shortest integral type for indices & value storage
# (e.g. char for values < 256).

dict for {property info} $properties {
    if {[dict get $info type] in {deprecated name}} continue

    set rangeValues $propertyValues($property)
    
    set Property [string totitle $property 0 0]
    set PROPERTY [string toupper $property]
    set padding [string repeat " " [expr {6-[string length $property]}]]

    #
    # Range array.
    #
    
    set ranges ""
    set nb 0
    dict for {cp value} $rangeValues {
        if {$cp == 0} continue
        
        if {($nb % 8) == 0} {
            # Wrap line.
            append ranges "\n    "
        }
        append ranges "$cp, "
        incr nb
    }
    append ranges \n
    if {[dict get $info type] eq "boolean"} {
        puts $out [subst -nobackslashes -nocommands $templates(rangeBooleanVar)]
    } else {
        puts $out [subst -nobackslashes -nocommands $templates(rangeVar)]
    }

    set nbRanges [expr {$nb+1}]
    puts $out [subst -nobackslashes -nocommands $templates(nbRangeConstant)]

    #
    # Value array.
    #
    
    switch [dict get $info type] {
        boolean {
            # Boolean property, only store first value as consecutive ranges have 
            # alternating values
            set value0 [string map {N 0 Y 1} [dict get $rangeValues 0x0000]]
            puts $out [subst -nobackslashes -nocommands $templates(valueBooleanVar)]
        }
        enum {
            # Enumerated values.
            set values ""
            set nb 0
            dict for {cp value} $rangeValues {
                if {($nb % 4) == 0} {
                    # Wrap line.
                    append values "\n    "
                }
                set VALUE [string toupper [string map {. _ - _} $value]]
                append values "[subst -nobackslashes -nocommands $templates(enumValue)], "
                incr nb
            }
            append values \n
            puts $out [subst -nobackslashes -nocommands $templates(valueEnumVar)]
        }
        cp {
            # Codepoint offset values.
            set values ""
            set nb 0
            dict for {cp value} $rangeValues {
                if {($nb % 16) == 0} {
                    # Wrap line.
                    append values "\n    "
                }
                append values "$value, "
                incr nb
            }
            append values \n
            puts $out [subst -nobackslashes -nocommands $templates(valueCpVar)]
        }
        numeric -
        string -
        mcp -
        enumList {
            # Value array contains indices to an atom array storing unique values.
            # Note: numeric properties are stored as strings.
            set uniqueValues [lsort -unique [dict values $rangeValues]]
            set valueIndices [dict create]
            set nb 0
            foreach value $uniqueValues {
                dict set valueIndices $value $nb
                incr nb
                if {[dict get $info type] ne "string" && $value ne "0"} {
                    incr nb [llength $value]
                }
            }
            set values ""
            set nb 0
            dict for {cp value} $rangeValues {
                if {($nb % 16) == 0} {
                    # Wrap line.
                    append values "\n    "
                }
                append values "[dict get $valueIndices $value], "
                incr nb
            }
            append values \n
            set valueType [expr {$nb<256?"char":$nb<65536?"short":"int"}]
            puts $out [subst -nobackslashes -nocommands $templates(valueAtomVar)]

            # Now output atoms.
            switch [dict get $info type] {
                numeric -
                string {
                    # Strings.
                    set atoms ""
                    set nb 0
                    foreach value $uniqueValues {
                        if {($nb % 8) == 0} {
                            # Wrap line.
                            append atoms "\n    "
                        }
                        append atoms "\"[string map {\\ \\\\ \" \\\"} $value]\", "
                        incr nb
                    }
                    append atoms \n
                    set atomType "char * const"
                    puts $out [subst -nobackslashes -nocommands $templates(atomVar)]
                }
                mcp {
                    # NUL-terminated codepoint lists.
                    # - For length=0, zero.
                    # - For length=1, offset then zero.
                    # - For length>1, zero-terminated list of codepoint.
                    set atoms ""
                    set nb 0
                    foreach value $uniqueValues {
                        if {$value ne "0"} {
                            # Values.
                            foreach v $value {
                                if {($nb % 16) == 0} {
                                    # Wrap line.
                                    append atoms "\n    "
                                }
                                append atoms "$v, "
                                incr nb
                            }
                        }
                        
                        # Terminator.
                        if {($nb % 16) == 0} {
                            # Wrap line.
                            append atoms "\n    "
                        }
                        append atoms "0, "
                        incr nb
                    }
                    append atoms \n
                    set atomType "int"
                    puts $out [subst -nobackslashes -nocommands $templates(atomVar)]
                }
                enumList {
                    # Zero-terminated list of enum values.
                    set elementProperty [dict get $info enumType]
                    set ElementProperty [string totitle $elementProperty 0 0]
                    set ELEMENT_PROPERTY [string toupper $elementProperty]
                    
                    set atoms ""
                    set nb 0
                    foreach value $uniqueValues {
                        foreach v $value {
                            if {($nb % 4) == 0} {
                                # Wrap line.
                                append atoms "\n    "
                            }
                            set ENUM_VALUE [string toupper [string map {. _ - _} $v]]
                            append atoms "[subst -nobackslashes -nocommands $templates(atomEnumValue)], "
                            incr nb
                        }
                        
                        # Terminator.
                        if {($nb % 4) == 0} {
                            # Wrap line.
                            append atoms "\n    "
                        }
                        append atoms "0, "
                        incr nb
                    }
                    append atoms \n
                    set nbValues [llength [dict get $properties $elementProperty values]]
                    set valueType [expr {$nbValues<256?"char":$nbValues<65536?"short":"int"}]
                    puts $out [subst -nobackslashes -nocommands $templates(atomEnumVar)]
                }
            }
        }
    }
}

#
# Now generate accessors for all known properties.
#

puts $out [subst -nobackslashes -nocommands $templates(ucdPropertyAccessorsGroup)]

dict for {property info} $properties {
    if {[dict get $info type] in {deprecated name}} continue

    set Property [string totitle $property 0 0]
    set PROPERTY [string toupper $property]

    set type [dict get $info type]
    if {$type eq "enumList"} {
        set elementProperty [dict get $info enumType]
        set ElementProperty [string totitle $elementProperty 0 0]
        set ELEMENT_PROPERTY [string toupper $elementProperty]
        
        set nbValues [llength [dict get $properties $elementProperty values]]
        set valueType [expr {$nbValues<256?"char":$nbValues<65536?"short":"int"}]
        puts $out [subst -nobackslashes -nocommands $templates(propertyAccessor_$type)]
    } else {
        puts $out [subst -nobackslashes -nocommands $templates(propertyAccessor_$type)]
    }
}

close $out


###############################################################################
#
# Regexp locale.
#
###############################################################################

source coatlUcd_regc_locale.tcl

set f [open regc_locale.tmpl.c]

unset -nocomplain templates; array set templates [read $f]
close $f

set out [open [file join $reroot regc_locale.c] w]
fconfigure $out -buffering line

puts $out [subst -nobackslashes -nocommands $templates(header)]

dict for {class criteria} $classes {
    puts $out [subst -nobackslashes -nocommands $templates(procDecl)]
}

set symbolInfos ""
dict for {symbol char} $symbols {
    scan $char %c c
    if {$c < 0x20} {
        set char [format "\\x%.2X" $c]
    } else {
        switch $char {
            \\ -
            ' -
            \" {set char \\$char}
        }
    }
    set padding [string repeat " " [expr {23-[string length $symbol]}]]
    append symbolInfos [subst -nobackslashes -nocommands $templates(symbolInfo)]
}
puts $out [subst -nobackslashes -nocommands $templates(symbols)]

set classInfos ""
dict for {class criteria} $classes {
    set CLASS [string toupper $class]

    if {[dict exists $classes_nocase $class]} {
        set classNocase [dict get $classes_nocase $class]
    } else {
        set classNocase $class
    }
    set padding [string repeat " " [expr {6-[string length $class]}]]
    append classInfos [subst -nobackslashes -nocommands $templates(classInfo)]
}
puts $out [subst -nobackslashes -nocommands $templates(classes)]

dict for {class criteria} $classes {
    set CLASS [string toupper $class]
    set padding [string repeat " " [expr {6-[string length $class]}]]

    set charValues [list]
    set rangeValues [list]
    foreach {type info} $criteria {
        switch $type {
            char {
                scan $info %c c
                lappend charValues [format "0x%.4X" $c]
            }
            range {
                lassign $info b e
                scan $b %c b
                scan $e %c e
                lappend rangeValues [format "0x%.4X" $b] [format "0x%.4X" $e]
            }
            property {
                lassign $info property re
                set match 0
                set lastCp 0
                dict for {cp value} $propertyValues($property) {
                    if {[regexp $re $value]} {
                        if {!$match} {
                            set lastCp $cp
                            set match 1
                        }
                    } elseif {$match && $cp != 0} {
                        if {$cp-$lastCp == 1} {
                            lappend charValues $lastCp
                        } else {
                            lappend rangeValues $lastCp [format "0x%.4X" [expr {$cp-1}]]
                        }
                        set match 0
                    }
                }
                if {$match} {
                    lappend rangeValues $lastCp COL_CHAR_MAX
                }
            }
        }
    }

    set nbChars [llength $charValues]
    if {$nbChars > 0} {
        set chars ""
        set nb 0
        foreach cp $charValues {
            if {($nb % 8) == 0} {
                # Wrap line.
                append chars "\n    "
            }
            append chars "$cp, "
            incr nb
        }
        append chars \n
        puts $out [subst -nobackslashes -nocommands $templates(charVar)]
    }
    puts $out [subst -nobackslashes -nocommands $templates(nbCharConstant)]
    
    set nbRanges [expr {[llength $rangeValues]/2}]
    if {$nbRanges > 0} {
        set ranges ""
        set nb 0
        foreach cp $rangeValues {
            if {($nb % 8) == 0} {
                # Wrap line.
                append ranges "\n    "
            }
            append ranges "$cp, "
            incr nb
        }
        append ranges \n
        puts $out [subst -nobackslashes -nocommands $templates(rangeVar)]
    }
    puts $out [subst -nobackslashes -nocommands $templates(nbRangeConstant)]
}

dict for {class criteria} $classes {
    set CLASS [string toupper $class]

    puts $out [subst -nobackslashes -nocommands $templates(procDef)]
}


puts $out [subst -nobackslashes -nocommands $templates(footer)]

close $out


exit

set classes [dict create {*}{
    alnum   {property {gc {^(L.|Nd)$}}}
    alpha   {property {gc {^L.$}}}
    ascii   {property {blk {^ASCII$}}}
    blank   {property {gc {^Zs$}} char \t}
    cased   {property {gc {^L[lut]$}}}
    cntrl   {property {gc {^Cc$}}}
    digit   {property {gc {^Nd$}}}
    graph   {property {gc {^[^ZC].$}}}
    lower   {property {gc {^Ll$}}}
    print   {property {gc {^[^C].$}}}
    punct   {property {gc {^(P.|S.)$}}}
    space   {property {WSpace {^Y$}}}
    upper   {property {gc {^Lu$}}}
    word    {property {gc {^(L.|N.|Pc)$}}}
    xdigit  {range {A F} range {a f} range {0 9}}
}]
set classes_nocase [dict create {*}{
	lower cased
	upper cased
}]

set symbols [dict create {*}{
    NUL						\x00
    SOH						\x01
    STX						\x02
    ETX						\x03
    EOT						\x04
    ENQ						\x05
    ACK						\x06
    BEL						\x07
    alert					\x07
    BS						\b
    backspace				\b
    HT						\t
    tab						\t
    LF						\n
    newline					\n
    VT						\v
    vertical-tab			\v
    FF						\f
    form-feed				\f
    CR						\r
    carriage-return			\r
    SO						\x0E
    SI						\x0F
    DLE						\x10
    DC1						\x11
    DC2						\x12
    DC3						\x13
    DC4						\x14
    NAK						\x15
    SYN						\x16
    ETB						\x17
    CAN						\x18
    EM						\x19
    SUB						\x1A
    ESC						\x1B
    IS4						\x1C
    FS						\x1C
    IS3						\x1D
    GS						\x1D
    IS2						\x1E
    RS						\x1E
    IS1						\x1F
    US						\x1F
    space					" "
    exclamation-mark		!
    quotation-mark			\"
    number-sign				#
    dollar-sign				$
    percent-sign			%
    ampersand				&
    apostrophe				'
    left-parenthesis		(
    right-parenthesis		)
    asterisk				*
    plus-sign				+
    comma					,
    hyphen					-
    hyphen-minus			-
    period					.
    full-stop				.
    slash					/
    solidus					/
    zero					0
    one						1
    two						2
    three					3
    four					4
    five					5
    six						6
    seven					7
    eight					8
    nine					9
    colon					:
    semicolon				;
    less-than-sign			<
    equals-sign				=
    greater-than-sign		>
    question-mark			?
    commercial-at			@
    left-square-bracket	 	[
    backslash				\\
    reverse-solidus			\\
    right-square-bracket	]
    circumflex				^
    circumflex-accent	 	^
    underscore				_
    low-line				_
    grave-accent			`
    left-brace				\{
    left-curly-bracket	 	\{
    vertical-line			|
    right-brace				\}
    right-curly-bracket	 	\}
    tilde					~
    DEL						\x7F
}]

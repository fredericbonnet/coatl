# Adapted from PropertyAliases-13.0.0.txt and UAX #44

set properties [dict create]

# ================================================
# Numeric Properties
# ================================================
# TODO UAX #38
# cjkAccountingNumeric     ; kAccountingNumeric
# cjkOtherNumeric          ; kOtherNumeric
# cjkPrimaryNumeric        ; kPrimaryNumeric
dict set properties nv                       {type numeric}

# ================================================
# String Properties
# ================================================
dict set properties cf                       {type mcp}
# TODO UAX #38
# cjkCompatibilityVariant  ; kCompatibilityVariant
dict set properties dm                       {type mcp}
dict set properties FC_NFKC                  {type deprecated}
dict set properties lc                       {type mcp}
dict set properties NFKC_CF                  {type mcp}
dict set properties scf                      {type cp}
dict set properties slc                      {type cp}
dict set properties stc                      {type cp}
dict set properties suc                      {type cp}
dict set properties tc                       {type mcp}
dict set properties uc                       {type mcp}

# ================================================
# Miscellaneous Properties
# ================================================
dict set properties bmg                      {type cp}
dict set properties bpb                      {type cp}
dict set properties isc                      {type deprecated}
dict set properties JSN                      {type name}
dict set properties na                       {type name}
dict set properties na1                      {type name}
dict set properties Name_Alias               {type name}
dict set properties scx                      {type enumList enumType sc}
# TODO UAX #38
#    cjkIICore                ; kIICore
#    cjkIRG_GSource           ; kIRG_GSource
#    cjkIRG_HSource           ; kIRG_HSource
#    cjkIRG_JSource           ; kIRG_JSource
#    cjkIRG_KPSource          ; kIRG_KPSource
#    cjkIRG_KSource           ; kIRG_KSource
#    cjkIRG_MSource           ; kIRG_MSource
#    cjkIRG_TSource           ; kIRG_TSource
#    cjkIRG_USource           ; kIRG_USource
#    cjkIRG_VSource           ; kIRG_VSource
#    cjkRSUnicode             ; kRSUnicode                  ; Unicode_Radical_Stroke; URS
#    EqUIdeo                  ; Equivalent_Unified_Ideograph

# ================================================
# Catalog Properties
# ================================================
dict set properties age                      {type enum}
dict set properties blk                      {type enum}
dict set properties sc                       {type enum}

# ================================================
# Enumerated Properties
# ================================================
dict set properties bc                       {type enum}
dict set properties bpt                      {type enum}
dict set properties ccc                      {type enum}
dict set properties dt                       {type enum}
dict set properties ea                       {type enum}
dict set properties gc                       {type enum}
dict set properties GCB                      {type enum}
dict set properties hst                      {type enum}
dict set properties InPC                     {type enum}
dict set properties InSC                     {type enum}
dict set properties jg                       {type enum}
dict set properties jt                       {type enum}
dict set properties lb                       {type enum}
dict set properties NFC_QC                   {type enum}
dict set properties NFD_QC                   {type enum}
dict set properties NFKC_QC                  {type enum}
dict set properties NFKD_QC                  {type enum}
dict set properties nt                       {type enum}
dict set properties SB                       {type enum}
dict set properties vo                       {type enum}
dict set properties WB                       {type enum}

# ================================================
# Binary Properties
# ================================================
dict set properties AHex                     {type boolean}
dict set properties Alpha                    {type boolean}
dict set properties Bidi_C                   {type boolean}
dict set properties Bidi_M                   {type boolean}
dict set properties Cased                    {type boolean}
dict set properties CE                       {type boolean}
dict set properties CI                       {type boolean}
dict set properties Comp_Ex                  {type boolean}
dict set properties CWCF                     {type boolean}
dict set properties CWCM                     {type boolean}
dict set properties CWKCF                    {type boolean}
dict set properties CWL                      {type boolean}
dict set properties CWT                      {type boolean}
dict set properties CWU                      {type boolean}
dict set properties Dash                     {type boolean}
dict set properties Dep                      {type boolean}
dict set properties DI                       {type boolean}
dict set properties Dia                      {type boolean}
dict set properties EBase                    {type boolean}
dict set properties EComp                    {type boolean}
dict set properties EMod                     {type boolean}
dict set properties Emoji                    {type boolean}
dict set properties EPres                    {type boolean}
dict set properties Ext                      {type boolean}
dict set properties ExtPict                  {type boolean}
dict set properties Gr_Base                  {type boolean}
dict set properties Gr_Ext                   {type boolean}
dict set properties Gr_Link                  {type deprecated}
dict set properties Hex                      {type boolean}
dict set properties Hyphen                   {type deprecated}
dict set properties IDC                      {type boolean}
dict set properties Ideo                     {type boolean}
dict set properties IDS                      {type boolean}
dict set properties IDSB                     {type boolean}
dict set properties IDST                     {type boolean}
dict set properties Join_C                   {type boolean}
dict set properties LOE                      {type boolean}
dict set properties Lower                    {type boolean}
dict set properties Math                     {type boolean}
dict set properties NChar                    {type boolean}
dict set properties OAlpha                   {type boolean}
dict set properties ODI                      {type boolean}
dict set properties OGr_Ext                  {type boolean}
dict set properties OIDC                     {type boolean}
dict set properties OIDS                     {type boolean}
dict set properties OLower                   {type boolean}
dict set properties OMath                    {type boolean}
dict set properties OUpper                   {type boolean}
dict set properties Pat_Syn                  {type boolean}
dict set properties Pat_WS                   {type boolean}
dict set properties PCM                      {type boolean}
dict set properties QMark                    {type boolean}
dict set properties Radical                  {type boolean}
dict set properties RI                       {type boolean}
dict set properties SD                       {type boolean}
dict set properties STerm                    {type boolean}
dict set properties Term                     {type boolean}
dict set properties UIdeo                    {type boolean}
dict set properties Upper                    {type boolean}
dict set properties VS                       {type boolean}
dict set properties WSpace                   {type boolean}
dict set properties XIDC                     {type boolean}
dict set properties XIDS                     {type boolean}
dict set properties XO_NFC                   {type deprecated}
dict set properties XO_NFD                   {type deprecated}
dict set properties XO_NFKC                  {type deprecated}
dict set properties XO_NFKD                  {type deprecated}

# ================================================
# Total:    129

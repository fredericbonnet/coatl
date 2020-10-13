/*
 * Header: coatlJson.h
 *
 *      This header file defines the JSON features of CoATL.
 */

#ifndef _COATL_JSON
#define _COATL_JSON

/*
================================================================================
Section: JSON Input/Output

Declarations:
        <Coatl_ReadJson>
================================================================================
*/

EXTERN int              Coatl_ReadJson(Col_RopeIterator begin, 
                            Col_RopeIterator end, Col_Word *wordPtr);
EXTERN size_t           Coatl_WriteJson(Col_Word strbuf, Col_Word word, 
                            size_t indent);

#endif /* _COATL_JSON */

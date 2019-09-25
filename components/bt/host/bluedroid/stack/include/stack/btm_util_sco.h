#pragma once
/**
  * @author  nif / nifoMorph
  * @brief   Utilities for mapping SCO flags into readable strings
  * ------------------------------------------------------------------------
  * Copyright nifoMorph ApS, 2019
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  * http://www.apache.org/licenses/LICENSE-2.0
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  * ------------------------------------------------------------------------
 **/
#include "btm_api.h"

#define BTM_SCO_PKT_TYPE_MASK_V(KIND,VARIANT...) BTM_SCO_PKT_TYPES_MASK##VARIANT##_##KIND


/*******************************************************************************
**
** Function         BTM_ScoPacketTypesToString
**
** Description      Map SCO packet type mask to a readable string.
**
** Parameters
**   p_strbuf       Pointer to a buffer for the result.
**                  Should be >= 80 bytes.
**                  If NULL, no string is generated, but the number of packet
**                  types matched are still returned.
**
**   pkttype_mask   Mask composed of bits from the definitions
**                  BTM_SCO_PKT_TYPES_MASK_...
**
**                  If no bits are set, the string "NUL" is returned.
**
**                  If bits, which do not correspond to a known packet type,
**                  are set, "X..." is added to the end of the string buffer
**                  and the return value is incremented by one.
**
** Returns          Number of known packet types in the mask.
**                  + 1 if one or more undefined bits are set.
**
*******************************************************************************/
UINT8 BTM_ScoPacketTypesToString (char* p_strbuf, UINT16 pkttype_mask);


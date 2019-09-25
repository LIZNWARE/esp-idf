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
#include "stack/btm_util_sco.h"


typedef struct tMask2StringMap* Mask2StringMapPtr;
typedef const struct tMask2StringMap* Mask2StringMapCPtr;
typedef struct tMask2StringMap
{
    long        mMask;
    const char* cszString;
} Mask2StringMapT;



#define _S(X,VARIANT) #VARIANT #X
#define _MMAP(X,VARIANT...) {.mMask = BTM_SCO_PKT_TYPE_MASK_V(X,VARIANT), .cszString = _S(X,VARIANT)}

const Mask2StringMapT aPktTypeStringMap[] =
{
    _MMAP(EV5,_NO_3),
    _MMAP(EV5,_NO_2),
    _MMAP(EV3,_NO_3),
    _MMAP(EV3,_NO_2),

    _MMAP(EV5),
    _MMAP(EV4),
    _MMAP(EV3),

    _MMAP(HV3),
    _MMAP(HV2),
    _MMAP(HV1),

    {.mMask = ~0, .cszString = "X..."} // Catch all / end marker

};


UINT8 BTM_ScoPacketTypesToString (char* p_strbuf, UINT16 pkttype_mask)
{
#if 0
  if(p_strbuf) *p_strbuf = 0;
  return 0;
#else
  int nRes = 0;
  char* pD = 0;
  long  mMask = pkttype_mask;
  Mask2StringMapCPtr pMap  = aPktTypeStringMap;

  while(mMask)
  {
    if(mMask & pMap->mMask)
    {
      nRes++;
      if(pD)
      {
        const char* pS = ",";
        while(*pS) {*pD++ = *pS++;}
      }
      else
      {
        pD = p_strbuf;
      }
      if(pD)
      {
        const char* pS = pMap->cszString;
        while(*pS) {*pD++ = *pS++;}
      }
      mMask &= ~pMap->mMask;
    }
    pMap++;
  }
  if(p_strbuf)
  {
    if(!pD)
    {
      pD = p_strbuf;
      const char* pS = "NUL";
      while(*pS) {*pD++ = *pS++;}
    }
    *pD = 0;
  }
  return nRes;
#endif
}

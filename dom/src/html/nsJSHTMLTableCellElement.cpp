/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 */
/* AUTO-GENERATED. DO NOT EDIT!!! */

#include "jsapi.h"
#include "nscore.h"
#include "nsIScriptContext.h"
#include "nsIJSScriptObject.h"
#include "nsIScriptObjectOwner.h"
#include "nsIScriptGlobalObject.h"
#include "nsIPtr.h"
#include "nsString.h"
#include "nsIDOMHTMLTableCellElement.h"


static NS_DEFINE_IID(kIScriptObjectOwnerIID, NS_ISCRIPTOBJECTOWNER_IID);
static NS_DEFINE_IID(kIJSScriptObjectIID, NS_IJSSCRIPTOBJECT_IID);
static NS_DEFINE_IID(kIScriptGlobalObjectIID, NS_ISCRIPTGLOBALOBJECT_IID);
static NS_DEFINE_IID(kIHTMLTableCellElementIID, NS_IDOMHTMLTABLECELLELEMENT_IID);

NS_DEF_PTR(nsIDOMHTMLTableCellElement);

//
// HTMLTableCellElement property ids
//
enum HTMLTableCellElement_slots {
  HTMLTABLECELLELEMENT_CELLINDEX = -11,
  HTMLTABLECELLELEMENT_ABBR = -12,
  HTMLTABLECELLELEMENT_ALIGN = -13,
  HTMLTABLECELLELEMENT_AXIS = -14,
  HTMLTABLECELLELEMENT_BGCOLOR = -15,
  HTMLTABLECELLELEMENT_CH = -16,
  HTMLTABLECELLELEMENT_CHOFF = -17,
  HTMLTABLECELLELEMENT_COLSPAN = -18,
  HTMLTABLECELLELEMENT_HEADERS = -19,
  HTMLTABLECELLELEMENT_HEIGHT = -110,
  HTMLTABLECELLELEMENT_NOWRAP = -111,
  HTMLTABLECELLELEMENT_ROWSPAN = -112,
  HTMLTABLECELLELEMENT_SCOPE = -113,
  HTMLTABLECELLELEMENT_VALIGN = -114,
  HTMLTABLECELLELEMENT_WIDTH = -115
};

/***********************************************************************/
//
// HTMLTableCellElement Properties Getter
//
PR_STATIC_CALLBACK(JSBool)
GetHTMLTableCellElementProperty(JSContext *cx, JSObject *obj, jsval id, jsval *vp)
{
  nsIDOMHTMLTableCellElement *a = (nsIDOMHTMLTableCellElement*)JS_GetPrivate(cx, obj);

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == a) {
    return JS_TRUE;
  }

  if (JSVAL_IS_INT(id)) {
    switch(JSVAL_TO_INT(id)) {
      case HTMLTABLECELLELEMENT_CELLINDEX:
      {
        PRInt32 prop;
        if (NS_OK == a->GetCellIndex(&prop)) {
          *vp = INT_TO_JSVAL(prop);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLECELLELEMENT_ABBR:
      {
        nsAutoString prop;
        if (NS_OK == a->GetAbbr(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLECELLELEMENT_ALIGN:
      {
        nsAutoString prop;
        if (NS_OK == a->GetAlign(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLECELLELEMENT_AXIS:
      {
        nsAutoString prop;
        if (NS_OK == a->GetAxis(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLECELLELEMENT_BGCOLOR:
      {
        nsAutoString prop;
        if (NS_OK == a->GetBgColor(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLECELLELEMENT_CH:
      {
        nsAutoString prop;
        if (NS_OK == a->GetCh(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLECELLELEMENT_CHOFF:
      {
        nsAutoString prop;
        if (NS_OK == a->GetChOff(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLECELLELEMENT_COLSPAN:
      {
        PRInt32 prop;
        if (NS_OK == a->GetColSpan(&prop)) {
          *vp = INT_TO_JSVAL(prop);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLECELLELEMENT_HEADERS:
      {
        nsAutoString prop;
        if (NS_OK == a->GetHeaders(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLECELLELEMENT_HEIGHT:
      {
        nsAutoString prop;
        if (NS_OK == a->GetHeight(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLECELLELEMENT_NOWRAP:
      {
        PRBool prop;
        if (NS_OK == a->GetNoWrap(&prop)) {
          *vp = BOOLEAN_TO_JSVAL(prop);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLECELLELEMENT_ROWSPAN:
      {
        PRInt32 prop;
        if (NS_OK == a->GetRowSpan(&prop)) {
          *vp = INT_TO_JSVAL(prop);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLECELLELEMENT_SCOPE:
      {
        nsAutoString prop;
        if (NS_OK == a->GetScope(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLECELLELEMENT_VALIGN:
      {
        nsAutoString prop;
        if (NS_OK == a->GetVAlign(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      case HTMLTABLECELLELEMENT_WIDTH:
      {
        nsAutoString prop;
        if (NS_OK == a->GetWidth(prop)) {
          JSString *jsstring = JS_NewUCStringCopyN(cx, prop, prop.Length());
          // set the return value
          *vp = STRING_TO_JSVAL(jsstring);
        }
        else {
          return JS_FALSE;
        }
        break;
      }
      default:
      {
        nsIJSScriptObject *object;
        if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
          PRBool rval;
          rval =  object->GetProperty(cx, id, vp);
          NS_RELEASE(object);
          return rval;
        }
      }
    }
  }
  else {
    nsIJSScriptObject *object;
    if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
      PRBool rval;
      rval =  object->GetProperty(cx, id, vp);
      NS_RELEASE(object);
      return rval;
    }
  }

  return PR_TRUE;
}

/***********************************************************************/
//
// HTMLTableCellElement Properties Setter
//
PR_STATIC_CALLBACK(JSBool)
SetHTMLTableCellElementProperty(JSContext *cx, JSObject *obj, jsval id, jsval *vp)
{
  nsIDOMHTMLTableCellElement *a = (nsIDOMHTMLTableCellElement*)JS_GetPrivate(cx, obj);

  // If there's no private data, this must be the prototype, so ignore
  if (nsnull == a) {
    return JS_TRUE;
  }

  if (JSVAL_IS_INT(id)) {
    switch(JSVAL_TO_INT(id)) {
      case HTMLTABLECELLELEMENT_CELLINDEX:
      {
        PRInt32 prop;
        int32 temp;
        if (JSVAL_IS_NUMBER(*vp) && JS_ValueToInt32(cx, *vp, &temp)) {
          prop = (PRInt32)temp;
        }
        else {
          JS_ReportError(cx, "Parameter must be a number");
          return JS_FALSE;
        }
      
        a->SetCellIndex(prop);
        
        break;
      }
      case HTMLTABLECELLELEMENT_ABBR:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetAbbr(prop);
        
        break;
      }
      case HTMLTABLECELLELEMENT_ALIGN:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetAlign(prop);
        
        break;
      }
      case HTMLTABLECELLELEMENT_AXIS:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetAxis(prop);
        
        break;
      }
      case HTMLTABLECELLELEMENT_BGCOLOR:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetBgColor(prop);
        
        break;
      }
      case HTMLTABLECELLELEMENT_CH:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetCh(prop);
        
        break;
      }
      case HTMLTABLECELLELEMENT_CHOFF:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetChOff(prop);
        
        break;
      }
      case HTMLTABLECELLELEMENT_COLSPAN:
      {
        PRInt32 prop;
        int32 temp;
        if (JSVAL_IS_NUMBER(*vp) && JS_ValueToInt32(cx, *vp, &temp)) {
          prop = (PRInt32)temp;
        }
        else {
          JS_ReportError(cx, "Parameter must be a number");
          return JS_FALSE;
        }
      
        a->SetColSpan(prop);
        
        break;
      }
      case HTMLTABLECELLELEMENT_HEADERS:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetHeaders(prop);
        
        break;
      }
      case HTMLTABLECELLELEMENT_HEIGHT:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetHeight(prop);
        
        break;
      }
      case HTMLTABLECELLELEMENT_NOWRAP:
      {
        PRBool prop;
        JSBool temp;
        if (JSVAL_IS_BOOLEAN(*vp) && JS_ValueToBoolean(cx, *vp, &temp)) {
          prop = (PRBool)temp;
        }
        else {
          JS_ReportError(cx, "Parameter must be a boolean");
          return JS_FALSE;
        }
      
        a->SetNoWrap(prop);
        
        break;
      }
      case HTMLTABLECELLELEMENT_ROWSPAN:
      {
        PRInt32 prop;
        int32 temp;
        if (JSVAL_IS_NUMBER(*vp) && JS_ValueToInt32(cx, *vp, &temp)) {
          prop = (PRInt32)temp;
        }
        else {
          JS_ReportError(cx, "Parameter must be a number");
          return JS_FALSE;
        }
      
        a->SetRowSpan(prop);
        
        break;
      }
      case HTMLTABLECELLELEMENT_SCOPE:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetScope(prop);
        
        break;
      }
      case HTMLTABLECELLELEMENT_VALIGN:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetVAlign(prop);
        
        break;
      }
      case HTMLTABLECELLELEMENT_WIDTH:
      {
        nsAutoString prop;
        JSString *jsstring;
        if ((jsstring = JS_ValueToString(cx, *vp)) != nsnull) {
          prop.SetString(JS_GetStringChars(jsstring));
        }
        else {
          prop.SetString((const char *)nsnull);
        }
      
        a->SetWidth(prop);
        
        break;
      }
      default:
      {
        nsIJSScriptObject *object;
        if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
          PRBool rval;
          rval =  object->SetProperty(cx, id, vp);
          NS_RELEASE(object);
          return rval;
        }
      }
    }
  }
  else {
    nsIJSScriptObject *object;
    if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
      PRBool rval;
      rval =  object->SetProperty(cx, id, vp);
      NS_RELEASE(object);
      return rval;
    }
  }

  return PR_TRUE;
}


//
// HTMLTableCellElement finalizer
//
PR_STATIC_CALLBACK(void)
FinalizeHTMLTableCellElement(JSContext *cx, JSObject *obj)
{
  nsIDOMHTMLTableCellElement *a = (nsIDOMHTMLTableCellElement*)JS_GetPrivate(cx, obj);
  
  if (nsnull != a) {
    // get the js object
    nsIScriptObjectOwner *owner = nsnull;
    if (NS_OK == a->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
      owner->ResetScriptObject();
      NS_RELEASE(owner);
    }

    NS_RELEASE(a);
  }
}


//
// HTMLTableCellElement enumerate
//
PR_STATIC_CALLBACK(JSBool)
EnumerateHTMLTableCellElement(JSContext *cx, JSObject *obj)
{
  nsIDOMHTMLTableCellElement *a = (nsIDOMHTMLTableCellElement*)JS_GetPrivate(cx, obj);
  
  if (nsnull != a) {
    // get the js object
    nsIJSScriptObject *object;
    if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
      object->EnumerateProperty(cx);
      NS_RELEASE(object);
    }
  }
  return JS_TRUE;
}


//
// HTMLTableCellElement resolve
//
PR_STATIC_CALLBACK(JSBool)
ResolveHTMLTableCellElement(JSContext *cx, JSObject *obj, jsval id)
{
  nsIDOMHTMLTableCellElement *a = (nsIDOMHTMLTableCellElement*)JS_GetPrivate(cx, obj);
  
  if (nsnull != a) {
    // get the js object
    nsIJSScriptObject *object;
    if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
      object->Resolve(cx, id);
      NS_RELEASE(object);
    }
  }
  return JS_TRUE;
}


/***********************************************************************/
//
// class for HTMLTableCellElement
//
JSClass HTMLTableCellElementClass = {
  "HTMLTableCellElement", 
  JSCLASS_HAS_PRIVATE,
  JS_PropertyStub,
  JS_PropertyStub,
  GetHTMLTableCellElementProperty,
  SetHTMLTableCellElementProperty,
  EnumerateHTMLTableCellElement,
  ResolveHTMLTableCellElement,
  JS_ConvertStub,
  FinalizeHTMLTableCellElement
};


//
// HTMLTableCellElement class properties
//
static JSPropertySpec HTMLTableCellElementProperties[] =
{
  {"cellIndex",    HTMLTABLECELLELEMENT_CELLINDEX,    JSPROP_ENUMERATE},
  {"abbr",    HTMLTABLECELLELEMENT_ABBR,    JSPROP_ENUMERATE},
  {"align",    HTMLTABLECELLELEMENT_ALIGN,    JSPROP_ENUMERATE},
  {"axis",    HTMLTABLECELLELEMENT_AXIS,    JSPROP_ENUMERATE},
  {"bgColor",    HTMLTABLECELLELEMENT_BGCOLOR,    JSPROP_ENUMERATE},
  {"ch",    HTMLTABLECELLELEMENT_CH,    JSPROP_ENUMERATE},
  {"chOff",    HTMLTABLECELLELEMENT_CHOFF,    JSPROP_ENUMERATE},
  {"colSpan",    HTMLTABLECELLELEMENT_COLSPAN,    JSPROP_ENUMERATE},
  {"headers",    HTMLTABLECELLELEMENT_HEADERS,    JSPROP_ENUMERATE},
  {"height",    HTMLTABLECELLELEMENT_HEIGHT,    JSPROP_ENUMERATE},
  {"noWrap",    HTMLTABLECELLELEMENT_NOWRAP,    JSPROP_ENUMERATE},
  {"rowSpan",    HTMLTABLECELLELEMENT_ROWSPAN,    JSPROP_ENUMERATE},
  {"scope",    HTMLTABLECELLELEMENT_SCOPE,    JSPROP_ENUMERATE},
  {"vAlign",    HTMLTABLECELLELEMENT_VALIGN,    JSPROP_ENUMERATE},
  {"width",    HTMLTABLECELLELEMENT_WIDTH,    JSPROP_ENUMERATE},
  {0}
};


//
// HTMLTableCellElement class methods
//
static JSFunctionSpec HTMLTableCellElementMethods[] = 
{
  {0}
};


//
// HTMLTableCellElement constructor
//
PR_STATIC_CALLBACK(JSBool)
HTMLTableCellElement(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
  nsIDOMHTMLTableCellElement *a = (nsIDOMHTMLTableCellElement*)JS_GetPrivate(cx, obj);
  PRBool result = PR_TRUE;
  
  if (nsnull != a) {
    // get the js object
    nsIJSScriptObject *object;
    if (NS_OK == a->QueryInterface(kIJSScriptObjectIID, (void**)&object)) {
      result = object->Construct(cx, obj, argc, argv, rval);
      NS_RELEASE(object);
    }
  }
  return (result == PR_TRUE) ? JS_TRUE : JS_FALSE;
}


//
// HTMLTableCellElement class initialization
//
nsresult NS_InitHTMLTableCellElementClass(nsIScriptContext *aContext, void **aPrototype)
{
  JSContext *jscontext = (JSContext *)aContext->GetNativeContext();
  JSObject *proto = nsnull;
  JSObject *constructor = nsnull;
  JSObject *parent_proto = nsnull;
  JSObject *global = JS_GetGlobalObject(jscontext);
  jsval vp;

  if ((PR_TRUE != JS_LookupProperty(jscontext, global, "HTMLTableCellElement", &vp)) ||
      !JSVAL_IS_OBJECT(vp) ||
      ((constructor = JSVAL_TO_OBJECT(vp)) == nsnull) ||
      (PR_TRUE != JS_LookupProperty(jscontext, JSVAL_TO_OBJECT(vp), "prototype", &vp)) || 
      !JSVAL_IS_OBJECT(vp)) {

    if (NS_OK != NS_InitHTMLElementClass(aContext, (void **)&parent_proto)) {
      return NS_ERROR_FAILURE;
    }
    proto = JS_InitClass(jscontext,     // context
                         global,        // global object
                         parent_proto,  // parent proto 
                         &HTMLTableCellElementClass,      // JSClass
                         HTMLTableCellElement,            // JSNative ctor
                         0,             // ctor args
                         HTMLTableCellElementProperties,  // proto props
                         HTMLTableCellElementMethods,     // proto funcs
                         nsnull,        // ctor props (static)
                         nsnull);       // ctor funcs (static)
    if (nsnull == proto) {
      return NS_ERROR_FAILURE;
    }

  }
  else if ((nsnull != constructor) && JSVAL_IS_OBJECT(vp)) {
    proto = JSVAL_TO_OBJECT(vp);
  }
  else {
    return NS_ERROR_FAILURE;
  }

  if (aPrototype) {
    *aPrototype = proto;
  }
  return NS_OK;
}


//
// Method for creating a new HTMLTableCellElement JavaScript object
//
extern "C" NS_DOM nsresult NS_NewScriptHTMLTableCellElement(nsIScriptContext *aContext, nsISupports *aSupports, nsISupports *aParent, void **aReturn)
{
  NS_PRECONDITION(nsnull != aContext && nsnull != aSupports && nsnull != aReturn, "null argument to NS_NewScriptHTMLTableCellElement");
  JSObject *proto;
  JSObject *parent;
  nsIScriptObjectOwner *owner;
  JSContext *jscontext = (JSContext *)aContext->GetNativeContext();
  nsresult result = NS_OK;
  nsIDOMHTMLTableCellElement *aHTMLTableCellElement;

  if (nsnull == aParent) {
    parent = nsnull;
  }
  else if (NS_OK == aParent->QueryInterface(kIScriptObjectOwnerIID, (void**)&owner)) {
    if (NS_OK != owner->GetScriptObject(aContext, (void **)&parent)) {
      NS_RELEASE(owner);
      return NS_ERROR_FAILURE;
    }
    NS_RELEASE(owner);
  }
  else {
    return NS_ERROR_FAILURE;
  }

  if (NS_OK != NS_InitHTMLTableCellElementClass(aContext, (void **)&proto)) {
    return NS_ERROR_FAILURE;
  }

  result = aSupports->QueryInterface(kIHTMLTableCellElementIID, (void **)&aHTMLTableCellElement);
  if (NS_OK != result) {
    return result;
  }

  // create a js object for this class
  *aReturn = JS_NewObject(jscontext, &HTMLTableCellElementClass, proto, parent);
  if (nsnull != *aReturn) {
    // connect the native object to the js object
    JS_SetPrivate(jscontext, (JSObject *)*aReturn, aHTMLTableCellElement);
  }
  else {
    NS_RELEASE(aHTMLTableCellElement);
    return NS_ERROR_FAILURE; 
  }

  return NS_OK;
}

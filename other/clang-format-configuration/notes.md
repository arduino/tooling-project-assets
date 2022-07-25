# ClangFormat configuration notes

## `BasedOnStyle`

This key is irrelevant because we define all configuration keys.

**ClangFormat** uses the `LLVM` style as a base by default.

## `BraceWrapping`

This key is ignored when `BreakBeforeBraces` is set to anything other than `Custom`.

## `CommentPragmas`

Setting this to an empty string (e.g., `""`) prevents any comments from being matched.

## `IncludeIsMainRegex`

Setting this to an empty string (e.g., `""`) prevents any `#include` directives from being matched.

## `MaxEmptyLinesToKeep`

Since the established behavior of the "Auto Format" feature from Arduino IDE 1.x is to allow any number of empty lines, this is set to a very large number to effectively reproduce the same.

## PointerAlignment

The `DerivePointerAlignment: true` configuration causes whatever pointer alignment style is predominant in the code to be used by **ClangFormat**. In the event no prevailing style can be can't be detected from code, this value is used as a fallback.

## `UseCRLF`

The `DeriveLineEnding: true` configuration causes whatever line endings are predominant in the code to be used by **ClangFormat**. In the event no prevailing style can be can't be detected from code, this value is used as a fallback.

## Keys specific to irrelevant languages

The following keys are specific to languages other than the Arduino/C++/C targeted by this configuration. For this reason, their values are inconsequential.

They should be set to **ClangFormat**'s default values.

### Java

- `BreakAfterJavaFieldAnnotations`
- `JavaImportGroups`

### JavaScript

- `JavaScriptQuotes`
- `JavaScriptWrapImports`

### Objective C-specific keys

- `AfterObjCDeclaration`
- `ObjCBinPackProtocolList`
- `ObjCBlockIndentWidth`
- `ObjCBreakBeforeNestedBlockParam`
- `ObjCSpaceAfterProperty`
- `ObjCSpaceBeforeProtocolList`

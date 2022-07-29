# ClangFormat configuration notes

## `AccessModifierOffset`

This is the additional indent beyond the standard code indentation level.

The Arduino IDE 1.x formatting style indented access modifiers (equivalent to `AccessModifierOffset: 0`), but also added an extra indent for the members. So non-indented access modifiers (`AccessModifierOffset: -2`) is actually closest to the previous formatting style.

## `BasedOnStyle`

This key is irrelevant because we define all configuration keys.

**ClangFormat** uses the `LLVM` style as a base by default.

## `BraceWrapping`

This key is ignored when `BreakBeforeBraces` is set to anything other than `Custom`.

## `BreakBeforeInheritanceComma`

Seems to be a backwards compatibility name for `BreakInheritanceList: BeforeComma`:

https://releases.llvm.org/6.0.0/tools/clang/docs/ClangFormatStyleOptions.html#configurable-format-style-options:~:text=BreakBeforeInheritanceComma

## `BreakConstructorInitializersBeforeComma`

Seems to be a backwards compatibility name for `BreakConstructorInitializers: BeforeComma`:

https://releases.llvm.org/3.8.0/tools/clang/docs/ClangFormatStyleOptions.html#configurable-format-style-options:~:text=BreakConstructorInitializersBeforeComma

## `CommentPragmas`

Setting this to an empty string (e.g., `""`) prevents any comments from being matched.

## `IncludeIsMainRegex`

Setting this to an empty string (e.g., `""`) prevents any `#include` directives from being matched.

## `KeepEmptyLinesAtTheStartOfBlocks`

Note that empty lines at the ends of blocks are always removed.

## `MaxEmptyLinesToKeep`

Since the established behavior of the "Auto Format" feature from Arduino IDE 1.x is to allow any number of empty lines, this is set to a very large number to effectively reproduce the same.

Note that empty lines at the ends of blocks are always removed.

## `NamespaceMacros`

This key is omitted from the `clang-format --dump-config` output when it is set to an empty array. Since Arduino's configuration does not have any need to define such macros, it is expected that this key will be absent from the configuration file even though present in the **ClangFormat** documentation.

## `PointerAlignment`

The `DerivePointerAlignment: true` configuration causes whatever pointer alignment style is predominant in the code to be used by **ClangFormat**. In the event no prevailing style can be can't be detected from code, this value is used as a fallback.

## `RawStringFormats`

This key is omitted from the `clang-format --dump-config` output when it is set to an empty array. Since Arduino's configuration does not have any need to define such formats, it is expected that this key will be absent from the configuration file even though present in the **ClangFormat** documentation.

## `TabWidth`

During the formatting process, **ClangFormat** always uses spaces initially for indentation and alignment, according to the `IndentWidth` configuration setting value.

If use of tabs for the final indents or alignment is indicated by the `UseTab` configuration setting, those spaces are then converted to tabs according to the value of `TabWidth`. For example, if `TabWidth` is set to `4`, then every occurrence of four spaces within the scope of the `UseTab` setting is converted to a tab.

This means there is a complex interaction between the `IndentWidth` and `TabWidth` values, which can produce unexpected results. For example, if `IndentWidth` is set to `2` and `TabWidth` to 4, every two indent levels is converted to a single tab, leaving two spaces for the final indentation of each odd level.

For this reason, `TabWidth` must always be set to the same value as `IndentWidth`.

## `TypenameMacros`

This key is omitted from the `clang-format --dump-config` output when it is set to an empty array. Since Arduino's configuration does not have any need to define such macros, it is expected that this key will be absent from the configuration file even though present in the **ClangFormat** documentation.

## `UseCRLF`

The `DeriveLineEnding: true` configuration causes whatever line endings are predominant in the code to be used by **ClangFormat**. In the event no prevailing style can be can't be detected from code, this value is used as a fallback.

## "Penalty" keys

These keys (e.g., `PenaltyBreakAssignment`) are not applicable when wrapping is disabled by setting `ColumnLimit` to `0`, as is done in Arduino's configuration. They are all arbitrarily set to `1`.

## Keys specific to irrelevant languages

The following keys are specific to languages other than the Arduino/C++/C targeted by this configuration. For this reason, their values are inconsequential.

They should be set to **ClangFormat**'s default values.

### Java

- `BreakAfterJavaFieldAnnotations`
- `JavaImportGroups`

### JavaScript

- `InsertTrailingCommas`
- `JavaScriptQuotes`
- `JavaScriptWrapImports`

### Objective C-specific keys

- `AfterObjCDeclaration`
- `ObjCBinPackProtocolList`
- `ObjCBlockIndentWidth`
- `ObjCBreakBeforeNestedBlockParam`
- `ObjCSpaceAfterProperty`
- `ObjCSpaceBeforeProtocolList`

## Keys with a forced base value set

Some [sequence type](https://www.yaml.info/learn/index.html#:~:text=A%20sequence%20is%20a%20list) keys have a base set of values which are hard coded into **ClangFormat**. These are appended to any custom values set in the configuration file and thus can not be overridden, even by setting the key to an empty array (e.g., `AttributeMacros: []`).

Arduino's configuration file sets these base set values explicitly even when they are not relevant to the Arduino code style. This provides transparency of the effective configuration and facilitates the maintenance of the configuration file

- `AttributeMacros`
- `ForEachMacros`
- `IfMacros`
- `IncludeCategories`
- `StatementAttributeLikeMacros`
- `StatementMacros`
- `WhitespaceSensitiveMacros`

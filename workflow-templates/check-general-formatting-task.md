# "Check General Formatting" workflow (task)

Workflow file: [check-general-formatting-task.yml](check-general-formatting-task.yml)

Use [editorconfig-checker](https://github.com/editorconfig-checker/editorconfig-checker) to check if the formatting of the repository's files match the [`.editorconfig`](https://editorconfig.org/).

## Assets

- [`.editorconfig`](assets/shared/.editorconfig)
  - Install to: repository root
- [`Taskfile.yml`](assets/check-general-formatting-task/Taskfile.yml] - formatting check [task](https://taskfile.dev/).
  - Install to: repository root (or add the `general:check-formatting` task into the existing `Taskfile.yml`)
- [`.ecrc`](assets/check-general-formatting-task/.ecrc) - editorconfig-checker configuration file.

The formatting style defined in `.editorconfig` is the official standardized style to be used in all Arduino tooling projects and should not be modified.

## Configuration

General formatting settings are configured in the [`.editorconfig` file](https://editorconfig.org/). [The standardized `.editorconfig`](assets/shared/.editorconfig) should be used in all Arduino Tooling repositories.

editorconfig-checker can be configured via an `.ecrc` file:
https://github.com/editorconfig-checker/editorconfig-checker#configuration

## Readme badge

Markdown badge:

```markdown
[![Check General Formatting status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-general-formatting-task.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-general-formatting-task.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-general-formatting-task.yml/badge.svg["Check General Formatting status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-general-formatting-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to check general file formatting

On every push, pull request, and periodically, check whether the repository's files are formatted according to
.editorconfig.
```

## PR message

```markdown
On every push, pull request, and periodically, use [editorconfig-checker](https://github.com/editorconfig-checker/editorconfig-checker) check whether the repository's files are formatted according to [`.editorconfig`](https://editorconfig.org/).
```

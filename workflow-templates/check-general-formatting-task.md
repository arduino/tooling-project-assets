# "Check General Formatting" workflow (task)

Use [editorconfig-checker](https://github.com/editorconfig-checker/editorconfig-checker) to check if the formatting of the repository's files matches the [`.editorconfig`](https://editorconfig.org/).

## Installation

### Workflow

Install the [`check-general-formatting-task.yml`](check-general-formatting-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`.editorconfig`](assets/general/.editorconfig)
  - Install to: repository root
- [`Taskfile.yml`](assets/check-general-formatting-task/Taskfile.yml) - formatting check [task](https://taskfile.dev/).
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`.ecrc`](assets/check-general-formatting/.ecrc) - editorconfig-checker configuration file.
  - Install to: repository root

The formatting style defined in `.editorconfig` is the official standardized style to be used in all Arduino tooling projects and should not be modified.

### Configuration

If the repository contains generated or vendored files, they can be excluded from the check by adding them to the `Exclude` array in the `.ecrc` configuration file.

Reference:
https://github.com/editorconfig-checker/editorconfig-checker#configuration

### Readme badge

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

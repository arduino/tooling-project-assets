# "Check Files" (Task)

Infrastructure for checking the project's filesystem.

[Tasks](https://taskfile.dev/) are provided to check for filesystem problems with the project content:

- Presence of characters prohibited by an operating system in filenames
- Use of filenames reserved by an operating system
- Broken symlinks
- Circular symlinks

A GitHub Actions workflow is included to run the tasks on any change to the project files, and periodically.

## Installation

### Workflow

Install the [`check-files-task.yml`](check-files-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`Taskfile.yml`](assets/check-files-task/Taskfile.yml) - file check [tasks](https://taskfile.dev/).
  - Install to: repository root (or merge into the existing `Taskfile.yml`).

### Readme badge

Markdown badge:

```markdown
[![Check Files status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-files-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-files-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-files-task.yml/badge.svg["Check Files status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-files-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```text
Add infrastructure for checking project filesystem

There are differences in the filename restrictions between operating systems. The use of filenames that are not valid
on one operating system in the project will cause problems for contributors or users (e.g., not possible to check out
the repository).

Tasks are added to check for non-portable filenames:

- Presence of characters prohibited by an operating system in filenames
- Use of filenames reserved by an operating system

Tasks are also added to check for problems with symbolic links ("symlinks") contained in the project:

- Broken symlinks
- Circular symlinks

A GitHub Actions workflow is included to automatically run the tasks. The workflow is triggered on any push or pull that
changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also
triggered periodically, in order to catch breakage caused by external changes.
```

## PR message

```markdown
There are differences in the filename restrictions between operating systems. The use of filenames that are not valid on one operating system in the project will cause problems for contributors or users (e.g., not possible to check out the repository).

Tasks are added to check for non-portable filenames:

- Presence of characters prohibited by an operating system in filenames
- Use of filenames reserved by an operating system

Tasks are also added to check for problems with symbolic links ("symlinks") contained in the project:

- Broken symlinks
- Circular symlinks

A GitHub Actions workflow is included to automatically run the tasks. The workflow is triggered on any push or pull that changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also triggered periodically, in order to catch breakage caused by external changes.
```

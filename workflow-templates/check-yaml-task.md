# "Check YAML" workflow (Task)

Run [yamllint](https://github.com/adrienverge/yamllint) on the YAML files of the repository.

NOTE: This workflow is focused on linting. Formatting checks for YAML are provided by the ["Check Prettier Formatting" workflow](check-prettier-formatting-task.md), so both should be used.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [check-yaml-task.yml](check-yaml-task.yml) GitHub Actions workflow to `.github/workflows/`

## Assets

- [`.yamllint.yml`](assets/check-yaml/.yamllint.yml) - `yamllint` configuration file.
  - Install to: repository root
- [`pyproject.toml`](assets/poetry/pyproject.toml) - [**Poetry**](https://python-poetry.org/) configuration.
  - Install to: repository root (unless a `pyproject.toml` file is already present).
- [`Taskfile.yml`](assets/check-yaml-task/Taskfile.yml) - Linting task.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/poetry-task/Taskfile.yml) - Installation task.
  - Merge into `Taskfile.yml`

The code style defined in this file is the official standardized style to be used in all Arduino tooling projects and should not be modified.

### Dependencies

Add the tool dependency using this command:

```
task poetry:install && poetry add --dev "yamllint@^1.37.1"
```

Commit the resulting changes to the `pyproject.toml` and `poetry.lock` files.

### Configuration

If the repository contains generated or vendored files, they can be excluded from the check by adding them to the `ignore` field in the `.yamllint.yml` configuration file.

Reference:
https://yamllint.readthedocs.io/en/stable/configuration.html

### Readme badge

Markdown badge:

```markdown
[![Check YAML status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-yaml-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-yaml-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-yaml-task.yml/badge.svg["Check YAML status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-yaml-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add infrastructure for linting YAML files

A task is provided to check for problems in the project's YAML files.

A GitHub Actions workflow is included to automatically run the task. The workflow is triggered on any push or pull that
changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also
triggered periodically, in order to catch breakage caused by external changes.
```

## PR message

```markdown
A task is provided to check for problems in the project's YAML files.

A GitHub Actions workflow is included to automatically run the task. The workflow is triggered on any push or pull that changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also triggered periodically, in order to catch breakage caused by external changes.
```

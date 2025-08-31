# "Check Poetry" workflow (Task)

Check for problems with configuration files of the [**Poetry**](https://python-poetry.org/) Python package manager.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [check-poetry-task.yml](check-poetry-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`Taskfile.yml`](assets/check-poetry-task/Taskfile.yml) - Validation tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/poetry-task/Taskfile.yml) - Installation task.
  - Merge into `Taskfile.yml`

## Readme badge

Markdown badge:

```markdown
[![Check Poetry status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-poetry-task.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-poetry-task.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-poetry-task.yml/badge.svg["Check YAML status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-poetry-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add infrastructure for checking Poetry configuration files

The project's Python package dependencies are managed using the "Poetry" tool.

Tasks and a GitHub Actions workflow are added to maintain and check for problems in the Poetry configuration files.

The tasks provide the following operations:

* Check for problems with the data structure of the `pyproject.toml` Python project file
* Update the `poetry.lock` file as may be required following manual modifications to `pyproject.toml`, or update of the
  "Poetry" application

A GitHub Actions workflow is included to automatically run the tasks. The workflow is triggered on any push or pull that
changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also
triggered periodically, in order to catch breakage caused by external changes.
```

## PR message

```markdown
The project's Python package dependencies are managed using the [**Poetry**](https://python-poetry.org/) tool.

[Tasks](https://taskfile.dev/) and a GitHub Actions workflow are added to maintain and check for problems in the **Poetry** configuration files.

The tasks provide the following operations:

- Check for problems with the data structure of the [`pyproject.toml`](https://python-poetry.org/docs/pyproject/) Python project file
- Update the `poetry.lock` file as may be required following manual modifications to `pyproject.toml`, or update of the **Poetry** application

A GitHub Actions workflow is included to automatically run the tasks. The workflow is triggered on any push or pull that changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also triggered periodically, in order to catch breakage caused by external changes.
```

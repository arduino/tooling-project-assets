# "Test Python" workflow (Poetry, Task)

Run [pytest](https://pytest.org)-based Python tests.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`test-python-poetry-task.yml`](test-python-poetry-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`pyproject.toml`](assets/poetry/pyproject.toml) - [**Poetry**](https://python-poetry.org/) configuration.
  - Install to: repository root (unless a `pyproject.toml` file is already present).
- [`Taskfile.yml`](assets/test-python-poetry-task/Taskfile.yml) - Test runner task.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/poetry-task/Taskfile.yml) - Installation task.
  - Merge into `Taskfile.yml`
- [`__init__.py`](assets/test-python/__init__.py) - Python module file.
  - Install to: `tests/`
- [`pytest.ini`](assets/test-python/pytest.ini) - [pytest](https://pytest.org) configuration file.
  - Install to: `tests/`
- [`.gitignore`](assets/python/.gitignore)
  - Install to: repository root (or merge into the existing `.gitignore`).

### Dependencies

Add the tool dependency using this command:

```
poetry add --dev "pytest@^8.4.1"
```

Commit the resulting changes to the `pyproject.toml` and `poetry.lock` files.

### Readme badge

Markdown badge:

```markdown
[![Test Python status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/test-python-poetry-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/test-python-poetry-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/test-python-poetry-task.yml/badge.svg["Test Python status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/test-python-poetry-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to run Python tests

On every push and pull request that affects relevant files, run the pytest-based Python tests.
```

## PR message

```markdown
On every push and pull request that affects relevant files, run the [pytest](https://pytest.org)-based Python tests.
```

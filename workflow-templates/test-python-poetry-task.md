# "Test Python" workflow (Poetry, Task)

Run [pytest](https://pytest.org)-based Python tests.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`test-python-poetry-task.yml`](test-python-poetry-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

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

The Python dependencies are managed by [Poetry](https://python-poetry.org/).

Install Poetry by following these instructions:<br />
https://python-poetry.org/docs/#installation

If your project does not already use Poetry, you can initialize the [`pyproject.toml`](https://python-poetry.org/docs/pyproject/) file using these commands:

```
poetry init --python="^3.9" --dev-dependency="pytest@^7.1.3"
poetry install
```

If already using Poetry, add the tool using this command:

```
poetry add --dev "pytest@^7.1.3"
```

Commit the resulting `pyproject.toml` and `poetry.lock` files.

### Configuration

Configure the version of Python used for development of the project in the `env.PYTHON_VERSION` field of `test-go-integration-task.yml`.

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

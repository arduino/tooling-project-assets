# "Test Integration" workflow (Go, Task)

Run Python integration tests for a [Go](https://golang.org/) module.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`test-go-integration-task.yml`](test-go-integration-task.yml) GitHub Actions workflow to `.github/workflows/`

## Assets

- [`Taskfile.yml`](assets/test-go-integration-task/Taskfile.yml) - Test runner task.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/go-task/Taskfile.yml) - Build task.
  - Merge into `Taskfile.yml`.
- [`Taskfile.yml`](assets/poetry-task/Taskfile.yml) - Dependencies installation task.
  - Merge into `Taskfile.yml`
- [`__init__.py`](assets/test-python/__init__.py) - Template for Python integration tests.
  - Install to: `tests/`
- [`test_all.py`](assets/test-integration/test_all.py) - Template for Python integration tests.
  - Install to: `tests/`
- [`pytest.ini`](assets/test-python/pytest.ini) - [pytest](https://pytest.org) configuration file.
  - Install to: `tests/`

### Dependencies

The Python dependencies are managed by [Poetry](https://python-poetry.org/).

Install Poetry by following these instructions:<br />
https://python-poetry.org/docs/#installation

If your project does not already use Poetry, you can initialize the [`pyproject.toml`](https://python-poetry.org/docs/pyproject/) file using these commands:

```
poetry init --python="^3.9" --dev-dependency="pytest@^7.3.2" --dev-dependency="invoke@^1.7.0"
poetry install
```

If already using Poetry, add the tool using this command:

```
poetry add --dev "pytest@^7.3.2" "invoke@^1.7.0"
```

Commit the resulting `pyproject.toml` and `poetry.lock` files.

### Configuration

#### Workflow

Configure the version of Go used for development of the project in the `env.GO_VERSION` field of `test-go-integration-task.yml`.

Configure the version of Python used for development of the project in the `env.PYTHON_VERSION` field of `test-go-integration-task.yml`.

#### Test helpers

Define the project's executable filename in the `executable_path` variable in `test_all.py`.

#### `.gitignore`

Add the following to `.gitignore`:

```
__pycache__/
<application executable>
<application executable>.exe
```

(where "`<application executable>`" is the filename of the Go application's executable)

### Readme badge

Markdown badge:

```markdown
[![Test Integration status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/test-go-integration-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/test-go-integration-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/test-go-integration-task.yml/badge.svg["Test Integration status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/test-go-integration-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to run integration tests

On every push and pull request that affects relevant files, run the integration tests.
```

## PR message

```markdown
On every push and pull request that affects relevant files, run the integration tests.
```

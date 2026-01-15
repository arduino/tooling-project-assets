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
- [`Taskfile.yml`](assets/windows-task/Taskfile.yml) - Utility tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`__init__.py`](assets/test-python/__init__.py) - Python module file.
  - Install to: `tests/`
- [`pytest.ini`](assets/test-python/pytest.ini) - [pytest](https://pytest.org) configuration file.
  - Install to: `tests/`
- [`.gitignore`](assets/python/.gitignore)
  - Install to: repository root (or merge into the existing `.gitignore`).

### Dependencies

#### Go Module-Managed Dependencies

If the project does not already have a `go.mod` file, [install **Go**](https://go.dev/doc/install) and then run the following command:

```text
go mod init <module path>
```

(where `<module path>` is the URL of the project repository without the scheme e.g., `github.com/foo/bar`)

Add the tool dependencies by running the following command:

```text
go get -tool github.com/go-task/task/v3/cmd/task@v3.44.1 github.com/mikefarah/yq/v4@v4.47.2
```

Commit the resulting changes to the `go.mod` and `go.sum` files.

#### Poetry-Managed Dependencies

Add the tool dependency using this command:

```
task poetry:install && poetry add --dev "pytest@^8.4.2"
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

# "Check Go" workflow (Task)

Lint and check formatting of a [Go](https://golang.org/) module.

## Installation

### Workflow

Install the [`check-go-task.yml`](check-go-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`Taskfile.yml`](assets/check-go-task/Taskfile.yml) - Linting and formatting [tasks](https://taskfile.dev/).
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`.golangci.yml`](assets/go/.golangci.yml) - Contains all the go-linting configurations.
  - Install to: repository root as `.golangci.yml`
- [`Taskfile.yml`](assets/go-task/Taskfile.yml) - `DEFAULT_GO_MODULE_PATH` and `DEFAULT_GO_PACKAGES` variables.
  - Merge into `Taskfile.yml`

### Configuration

If the project contains Go modules in paths other than the root of the repository, add their paths to the [job matrices](https://docs.github.com/actions/reference/workflows-and-actions/workflow-syntax#jobsjob_idstrategymatrix) of `check-go-task.yml` at:

- `jobs.check-errors.strategy.matrix.module[].path`
- `jobs.check-outdated.strategy.matrix.module[].path`
- `jobs.check-style.strategy.matrix.module[].path`
- `jobs.check-formatting.strategy.matrix.module[].path`
- `jobs.check-config.strategy.matrix.module[].path`

### Readme badge

Markdown badge:

```markdown
[![Check Go status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-go-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-go-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-go-task.yml/badge.svg["Check Go status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-go-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add infrastructure to lint and format Go code

Tasks are provided to format and check for problems in the project's Go modules.

A GitHub Actions workflow is included to automatically run the tasks. The workflow is triggered on any push or pull that
changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also
triggered periodically, in order to catch breakage caused by external changes.
```

## PR message

```markdown
Tasks are provided to format and check for problems in the project's [Go](https://golang.org/) modules.

A GitHub Actions workflow is included to automatically run the tasks. The workflow is triggered on any push or pull that changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also triggered periodically, in order to catch breakage caused by external changes.
```

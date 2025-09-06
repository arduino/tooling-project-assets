# "Test Go" workflow (Task)

Run the [Go](https://golang.org/) module's tests.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`test-go-task.yml`](test-go-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`Taskfile.yml`](assets/test-go-task/Taskfile.yml)
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/go-task/Taskfile.yml) - `DEFAULT_GO_MODULE_PATH` and `DEFAULT_GO_PACKAGES` variables
  - Merge into `Taskfile.yml`

### Configuration

#### Workflow

If the project contains Go modules in paths other than the root of the repository, add their paths to the [job matrix](https://docs.github.com/actions/reference/workflows-and-actions/workflow-syntax#jobsjob_idstrategymatrixx) in `check-go-task.yml` at `jobs.test.strategy.matrix.module[].path` and the [Codecov flag](https://docs.codecov.com/docs/flags) to group their data under at `jobs.test.strategy.matrix.module[].codecov-flags`

Replace `TODO_REPO_OWNER/TODO_REPO_NAME` with the repository's name (e.g., `arduino/arduino-cli`) in the `codecov/codecov-action` action's `fail_ci_if_error` input in `test-go-task.yml`.

#### `.gitignore`

Add the following to `.gitignore`:

```
<application executable>
<application executable>.exe
```

(where "`<application executable>`" is the filename of the Go application's executable)

### Readme badge

Markdown badge:

```markdown
[![Test Go status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/test-go-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/test-go-task.yml)
[![Codecov](https://codecov.io/gh/TODO_REPO_OWNER/TODO_REPO_NAME/branch/main/graph/badge.svg)](https://codecov.io/gh/TODO_REPO_OWNER/TODO_REPO_NAME)
```

- Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).
- If the coverage badge should reflect the coverage for a branch named something other than `main`, adjust the badge URL accordingly.

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/test-go-task.yml/badge.svg["Test Go status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/test-go-task.yml"]
image:https://codecov.io/gh/{repository-owner}/{repository-name}/branch/main/graph/badge.svg["Codecov", link="https://codecov.io/gh/{repository-owner}/{repository-name}"]
```

- Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).
- If the coverage badge should reflect the coverage for a branch named something other than `main`, adjust the badge URL accordingly.

## Commit message

```
Add infrastructure to test Go code

A task is provided to run the project's Go code tests.

A GitHub Actions workflow is included to automatically run the task. The workflow is triggered on any push or pull that
changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also
triggered periodically, in order to catch breakage caused by external changes.
```

## PR message

```markdown
A task is provided to run the project's [Go](https://golang.org/) code tests.

A GitHub Actions workflow is included to automatically run the task. The workflow is triggered on any push or pull that changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also triggered periodically, in order to catch breakage caused by external changes.
```

# "Test Go" workflow (Task)

Run the [Go](https://golang.org/) module's tests.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`test-go-task.yml`](test-go-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`Taskfile.yml`](assets/test-go-task/Taskfile.yml)
  - Install to: repository root (or merge into the existing `Taskfile.yml`).

### Configuration

#### Workflow

Configure the version of Go used for development of the project in the `env.GO_VERSION` field of `test-go-task.yml`.

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
[![Test Go status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/test-go-task.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/test-go-task.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/test-go-task.yml/badge.svg["Test Go status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/test-go-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to test Go code

On every push and pull request that affects relevant files, run the project's Go code tests.
```

## PR message

```markdown
On every push and pull request that affects relevant files, run the project's [Go](https://golang.org/) code tests.
```

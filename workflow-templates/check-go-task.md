# "Check Go" workflow (Task)

Lint and check formatting of a [Go](https://golang.org/) module.

## Installation

### Workflow

Install the [`check-go-task.yml`](check-go-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`Taskfile.yml`](assets/check-go-task/Taskfile.yml) - Linting and formatting [tasks](https://taskfile.dev/).
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/go-task/Taskfile.yml) - `DEFAULT_GO_MODULE_PATH` and `DEFAULT_GO_PACKAGES` variables
  - Merge into `Taskfile.yml`

### Configuration

Configure the version of Go used for development of the project in the `env.GO_VERSION` field of `check-go-task.yml`.

If the project contains Go modules in paths other than the root of the repository, add their paths to the [job matrices](https://docs.github.com/actions/reference/workflow-syntax-for-github-actions#jobsjob_idstrategymatrix) of `check-go-task.yml` at:

- `jobs.check-errors.strategy.matrix.module[].path`
- `jobs.check-outdated.strategy.matrix.module[].path`
- `jobs.check-style.strategy.matrix.module[].path`
- `jobs.check-formatting.strategy.matrix.module[].path`
- `jobs.check-config.strategy.matrix.module[].path`

### Readme badge

Markdown badge:

```markdown
[![Check Go status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-go-task.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-go-task.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-go-task.yml/badge.svg["Check Go status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-go-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to lint and check formatting of Go code

On every push and pull request that affects relevant files, check the Go module for:

- Common detectable errors in the code.
- Use of outdated APIs
- Code style violations
- Code formatting inconsistency
- Misconfiguration
```

## PR message

```markdown
On every push and pull request that affects relevant files, check the repository's [Go](https://golang.org/) module for:

- Common detectable errors in the code.
- Use of outdated APIs
- Code style violations
- Code formatting inconsistency
- Misconfiguration
```

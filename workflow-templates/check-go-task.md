# "Check Go" workflow (Task)

Workflow file: [`check-go-task.yml`](check-go-task.yml)

Lint and check formatting of a [Go](https://golang.org/) module.

## Assets

- [`Taskfile.yml`](assets/check-go-task/Taskfile.yml) - Linting and formatting [tasks](https://taskfile.dev/).
  - Install to: repository root (or merge into the existing `Taskfile.yml`).

## Readme badge

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

# "Test Go" workflow (Task)

Workflow file: [test-go-task.yml](test-go-task.yml)

Lint and check formatting of a [Go](https://golang.org/) module.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Assets

- [`Taskfile.yml`](assets/test-go-task/Taskfile.yml]
  - Install to: repository root (or add the `go:test` task into the existing `Taskfile.yml`)

## Readme badge

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

On every push and pull request that affects relevant files:

- Build the project.
- Upload the binary as a workflow artifact to allow interested parties to try it out without needing to build it
  themselves.
- Run the project's Go code tests.
```

## PR message

```markdown
On every push and pull request that affects relevant files:

- Build the project.
- Upload the binary as a workflow artifact to allow interested parties to try it out without needing to build it
  themselves.
- Run the project's [Golang](https://golang.org/) code tests.
```

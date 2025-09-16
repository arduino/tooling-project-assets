# "Publish Tester Build" workflow (Go, Task)

Publish tester builds of a [Go](https://golang.org/) project as [GitHub Actions workflow artifacts](https://docs.github.com/actions/tutorials/store-and-share-data) for every commit to a pull request or the repository.

This makes it possible for any interested party to participate in beta testing without setting up a build system locally.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`publish-go-tester-task.yml`](publish-go-tester-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`Taskfile.yml`](assets/release-go-task/Taskfile.yml) - [variables](https://taskfile.dev/#/usage?id=variables) providing project-specific data to the build system.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`DistTasks.yml`](assets/release-go-task/DistTasks.yml) - general purpose tasks for making production builds of Go projects using cgo and [elastic docker containers](https://github.com/elastic/golang-crossbuild).
  - Install to: repository root

### Configuration

#### Workflow

`PROJECT_NAME` must be set to the project-specific name in `publish-go-tester-task.yml`.

### Readme badge

Markdown badge:

```markdown
[![Publish Tester Build status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/publish-go-tester-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/publish-go-tester-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/publish-go-tester-task.yml/badge.svg["Publish Tester Build status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/publish-go-tester-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to publish tester builds

On every commit to a pull request or the repository:

- Build the project for all supported platforms.
- Upload the builds as workflow artifacts.

This makes it possible for any interested party to participate in beta testing without setting up a build system locally.
```

## PR message

```markdown
On every commit to a pull request or the repository:

- Build the project for all supported platforms.
- Upload the builds as [workflow artifacts](https://docs.github.com/en/actions/tutorials/store-and-share-data).

This makes it possible for any interested party to participate in beta testing without setting up a build system locally.
```

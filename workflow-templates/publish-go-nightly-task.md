# "Publish Nightly Build" workflow (Go, Task)

Publish nightly builds of a [Go](https://golang.org/) project.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`publish-go-nightly-task.yml`](publish-go-nightly-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

See [the "Release" workflow (Go, Task) documentation](release-go-task.md#assets)

### Configuration

See [the "Release" workflow (Go, Task) documentation](release-go-task.md#configuration)

In addition, the following [repository secret](https://docs.github.com/actions/how-tos/write-workflows/choose-what-workflows-do/use-secrets#creating-encrypted-secrets-for-a-repository) must be defined:

- `DD_API_KEY` - [Datadog](https://www.datadoghq.com/) API key.

### Readme badge

Markdown badge:

```markdown
[![Publish Nightly Build status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/publish-go-nightly-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/publish-go-nightly-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/publish-go-nightly-task.yml/badge.svg["Publish Nightly Build status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/publish-go-nightly-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to publish nightly builds

On a daily schedule:

- Build the project for all supported platforms.
- Sign and notarize the macOS builds.
- Upload the builds to Arduino's downloads server.

This will enable everyone to participate in the project's development via beta testing.
```

## PR message

```markdown
On a daily schedule:

- Build the project for all supported platforms.
- Use [gon](https://github.com/Bearer/gon) to sign and notarize the macOS builds.
- Upload the builds to Arduino's downloads server.

This will enable everyone to participate in the project's development via beta testing.
```

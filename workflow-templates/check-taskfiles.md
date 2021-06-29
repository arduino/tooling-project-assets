# "Check Taskfiles" workflow

Validate the repository's [Taskfiles](https://taskfile.dev/#/usage) against the JSON schema.

## Installation

### Workflow

Install the [`check-taskfiles.yml`](check-taskfiles.yml) GitHub Actions workflow to `.github/workflows/`

### Configuration

The workflow is configured to check all files named `Taskfile.yml` in the repository. If there are additional taskfiles, add them to the following fields in `check-taskfiles.yml`:

- `on.push.paths`
- `on.pull_request.paths`
- `jobs.validate.strategy.matrix.file[]`

### Readme badge

Markdown badge:

```markdown
[![Check Taskfiles status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-taskfiles.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-taskfiles.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-taskfiles.yml/badge.svg["Check Taskfiles status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-taskfiles.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to validate Taskfiles

On every push or pull request that affects the repository's Taskfiles, and periodically, validate them
against the JSON schema.
```

## PR message

```markdown
On every push or pull request that affects the repository's [Taskfiles](https://taskfile.dev/#/usage), and periodically, validate them against the JSON schema.
```

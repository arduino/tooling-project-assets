# "Check npm" workflow (Task)

Check for problems with configuration files of the [npm](https://www.npmjs.com/) JavaScript package manager.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [check-npm-task.yml](check-npm-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`.npmrc`](assets/npm/.npmrc) - **npm** configuration file.
  - Install to: repository root.
- [`Taskfile.yml`](assets/npm-task/Taskfile.yml) - npm tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/check-npm-task/Taskfile.yml) - Validation task.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`Taskfile.yml`](assets/windows-task/Taskfile.yml) - Utility tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).

### Configuration

#### Node.js

Configure the version of [**Node.js**](https://nodejs.org) used for development of the project by running the following command from a terminal in the project repository folder:

```text
npm pkg set engines.node=22.x
```

If the project contains **npm**-managed projects (i.e., a folder containing a `package.json` file) in paths other than the root of the repository, run the command again from each of those paths.

#### Workflow

If the project contains **npm**-managed projects (i.e., a folder containing a `package.json` file) in paths other than the root of the repository, add their paths to the [job matrices](https://docs.github.com/actions/reference/workflows-and-actions/workflow-syntax#jobsjob_idstrategymatrix) of `check-npm-task.yml` at:

- `jobs.validate.strategy.matrix.project[].path`
- `jobs.check-sync.strategy.matrix.project[].path`

## Readme badge

Markdown badge:

```markdown
[![Check npm status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-npm-task.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-npm-task.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-npm-task.yml/badge.svg["Check YAML status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-npm-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add infrastructure to check for problems with npm configuration files

Tasks are provided to check for problems in the project's npm configuration files:

* Validate package.json against its JSON schema.
* Check for forgotten package-lock.json syncs.

A GitHub Actions workflow is included to automatically run the tasks. The workflow is triggered on any push or pull that
changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also
triggered periodically, in order to catch breakage caused by external changes.
```

## PR message

```markdown
Tasks are provided to check for problems in the project's npm configuration files:

- Validate [`package.json`](https://docs.npmjs.com/cli/v7/configuring-npm/package-json) against [its JSON schema](https://json.schemastore.org/package.json).
- Check for forgotten [`package-lock.json`](https://docs.npmjs.com/cli/v7/configuring-npm/package-lock-json) syncs.

A GitHub Actions workflow is included to automatically run the tasks. The workflow is triggered on any push or pull that changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also triggered periodically, in order to catch breakage caused by external changes.
```

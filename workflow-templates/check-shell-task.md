# "Check Shell Scripts" workflow (Task)

Check the repository's shell scripts for problems:

- Static analysis using [ShellCheck](https://github.com/koalaman/shellcheck).
- Formatting using [shfmt](https://github.com/mvdan/sh).
- Forgotten executable script file permissions.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Installation

### Workflow

Install the [`check-shell-task.yml`](check-shell-task.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`.editorconfig`](assets/general/.editorconfig) - `shfmt` will use this [configuration file](https://editorconfig.org/).
  - Install to: repository root
- [`Taskfile.yml`](assets/check-shell-task/Taskfile.yml) - Tasks for checking shell scripts.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).

The formatting style defined in `.editorconfig` is the official standardized style to be used in all Arduino tooling projects and should not be modified.

### Configuration

Configure the paths of the shell scripts to be checked as elements in the [job matrices](https://docs.github.com/actions/reference/workflows-and-actions/workflow-syntax#jobsjob_idstrategymatrix) of `check-shell-task.yml` at:

- `jobs.lint.strategy.matrix.script[]`
- `jobs.formatting.strategy.matrix.script[]`
- `jobs.executable.strategy.matrix.script[]`

#### Example:

```yaml
matrix:
  script:
    - path/to/some-script.sh
    - path/to/another-script.sh
```

#### Paths filters

The workflow is configured to be triggered on changes to any files in the repository that have a `.sh` or `.bash` file extension. If the project contains shell scripts without a file extension, the path to those scripts must be added to the following keys in `check-shell-task.yml`:

- `on.push.paths[]`
- `on.pull_request.paths[]`

### Readme badge

Markdown badge:

```markdown
[![Check Shell Scripts status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-shell-task.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/check-shell-task.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-shell-task.yml/badge.svg["Check Shell Scripts status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-shell-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add infrastructure to check for problems with shell scripts

Tasks are provided to facilitate the development of the project's shell scripts:

- Detect common problems using ShellCheck.
- Format using shfmt.
- Check for forgotten executable script file permissions.

A GitHub Actions workflow is included to automatically run the tasks. The workflow is triggered on any push or pull that
changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also
triggered periodically, in order to catch breakage caused by external changes.
```

## PR message

```markdown
Tasks are provided to facilitate the development of the project's shell scripts:

- Detect common problems using [**ShellCheck**](https://github.com/koalaman/shellcheck).
- Format using [**shfmt**](https://github.com/mvdan/sh).
- Check for forgotten executable script file permissions.

A GitHub Actions workflow is included to automatically run the tasks. The workflow is triggered on any push or pull that changes relevant project files, in order to avoid the introduction of problems with the project filesystem. It is also triggered periodically, in order to catch breakage caused by external changes.
```

## Usage

In addition to the automated checks provided by the GitHub Actions workflow, the tasks can be ran locally.

### Prerequisites

The following development tools must be available in your local environment:

- [**ShellCheck**](https://github.com/koalaman/shellcheck#installing) - shell script static analysis tool.
- [**shfmt**](https://github.com/mvdan/sh#shfmt) - shell script formatting tool.
- [**Task**](https://taskfile.dev/installation/) task runner tool.

### Run static analysis

```text
task shell:check SCRIPT_PATH="<script path>"
```

(where `<script path>` is the path to the script file)

### Check file permissions

```text
task shell:check-mode SCRIPT_PATH="<script path>"
```

(where `<script path>` is the path to the script file)

### Format script

```text
task shell:format SCRIPT_PATH="<script path>"
```

(where `<script path>` is the path to the script file)

# "Check Shell Scripts" workflow (Task)

Workflow file: [`check-shell-task.yml`](check-shell-task.yml)

Check the repository's shell scripts for problems:

- Static analysis using [ShellCheck](https://github.com/koalaman/shellcheck).
- Formatting using [shfmt](https://github.com/mvdan/sh).
- Forgotten executable script file permissions.

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Assets

- [`.editorconfig`](assets/shared/.editorconfig) - `shfmt` will use this [configuration file](https://editorconfig.org/).
  - Install to: repository root
- [`Taskfile.yml`](assets/check-prettier-formatting-task/Taskfile.yml] - Tasks for checking shell scripts.
  - Install to: repository root (or add the tasks into the existing `Taskfile.yml`)

The formatting style defined in `.editorconfig` is the official standardized style to be used in all Arduino tooling projects and should not be modified.

## Readme badge

Markdown badge:

```markdown
[![Check Shell Scripts status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-shell-task.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-shell-task.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-shell-task.yml/badge.svg["Check Shell Scripts status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-shell-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to check for problems with shell scripts

On every push or pull request that modifies one of the shell scripts in the repository, and periodically, the workflow:

- Runs ShellCheck to detect common problems.
- Runs shfmt to check formatting.
- Checks for forgotten executable script file permissions.
```

## PR message

```markdown
On every push or pull request that modifies one of the shell scripts in the repository, and periodically, the workflow:

- Runs [ShellCheck](https://github.com/koalaman/shellcheck) to detect common problems.
- Runs [`shfmt`](https://github.com/mvdan/sh) to check formatting.
- Checks for forgotten executable script file permissions.
```

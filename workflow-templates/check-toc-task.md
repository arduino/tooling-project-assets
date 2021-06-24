# "Check ToC" workflow (Task)

Workflow file: [`check-toc-task.yml`](check-toc-task.yml)

Check whether the generated table of contents in Markdown files matches their heading structure.

This should be used in repositories that generate the table of contents with [markdown-toc](https://github.com/jonschlinkert/markdown-toc).

This is the version of the workflow for projects using the [Task](https://taskfile.dev/#/) task runner tool.

## Assets

- [`Taskfile.yml`](assets/check-toc-task/Taskfile.yml) - Table of contents generation task.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).

## Readme badge

Markdown badge:

```markdown
[![Check ToC status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-toc-task.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-toc-task.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-toc-task.yml/badge.svg["Check ToC status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-toc-task.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to check for missed updates to readme ToC

On every push or pull request that affects the repository's README.md, check whether the table of contents matches the
content.
```

## PR message

```markdown
On every push or pull request that affects the repository's `README.md`, use [markdown-toc](https://github.com/jonschlinkert/markdown-toc) to check whether the table of contents matches the content.
```

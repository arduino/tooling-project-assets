# "Deploy Website" workflow (MkDocs, Poetry)

Deploy a [MkDocs](https://www.mkdocs.org/)-based static website to [GitHub Pages](https://pages.github.com/).

This is the version of the workflow for projects using the [Poetry](https://python-poetry.org/) dependency management tool.

## Installation

### Workflow

Install the [`deploy-mkdocs-poetry.yml`](deploy-mkdocs-poetry.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`pyproject.toml`](assets/poetry/pyproject.toml) - [**Poetry**](https://python-poetry.org/) configuration.
  - Install to: repository root (unless a `pyproject.toml` file is already present).
- [`Taskfile.yml`](assets/poetry-task/Taskfile.yml) - Python package dependency management tasks.
  - Install to: repository root (or merge into the existing `Taskfile.yml`).
- [`mkdocs.yml`](assets/mkdocs/mkdocs.yml) - base MkDocs configuration file.
  - Install to: repository root
- [`icon_mac_light.png`](assets/mkdocs/icon_mac_light.png) - Arduino logo for the website. **NOTE**: only for use in official Arduino projects. Community projects should use [the Community Logo](https://www.arduino.cc/en/Trademark/CommunityLogo).
  - Install to: `docs/img/`

### Dependencies

Add the tool dependencies using this command:

```
task poetry:install && poetry add --dev "mkdocs@^1.3.0" "mkdocs-material@^8.2.11" "mdx_truly_sane_lists@^1.2"
```

Commit the resulting changes to the `pyproject.toml` and `poetry.lock` files.

### Configuration

#### Workflow

The workflow is configured for repositories that host the website source content in a branch named `main`. If the project uses a different branch, adjust the `on.push.branches[]` value in `deploy-mkdocs-poetry.yml`.

#### MkDocs

Replace all `TODO_*` placeholders in `mkdocs.yml` with the project-specific information.

Add entries for each website source file to the `nav` array in `mkdocs.yml`, or remove `nav` to have MkDocs auto-generate the navigation panel.

Reference: https://www.mkdocs.org/user-guide/configuration/

### Documentation

#### Readme badge

Markdown badge:

```markdown
[![Deploy Website status](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/deploy-mkdocs-poetry.yml/badge.svg)](https://github.com/TODO_REPO_OWNER/TODO_REPO_NAME/actions/workflows/deploy-mkdocs-poetry.yml)
```

Replace the `TODO_REPO_OWNER` and `TODO_REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/deploy-mkdocs-poetry.yml/badge.svg["Deploy Website status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/deploy-mkdocs-poetry.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

#### Development Guide

Add the following to the project's development documentation (templates available [here](../documentation-templates/README.md#development-guide)):

````markdown
## Documentation

The [Markdown](https://www.markdownguide.org/basic-syntax/) files under the `docs` subfolder of the repository are the source content for the project's documentation website.

When working on the documentation, it may be useful to see the effect the changes will have on the generated documentation website. You can build the documentation website and serve it from your personal computer by running this command from the project root:

```text
task website:serve
```

The website will now build. If you don't see any error, open `http://127.0.0.1:8000` in your browser to load the local copy of the documentation site.
````

## Commit message

```
Add CI workflow to deploy a MkDocs-based website to GitHub Pages

On every push to the repository's default branch, deploy the repository's MkDocs-based static website to GitHub Pages.
```

## PR message

```markdown
On every push to the repository's default branch, deploy the repository's [MkDocs](https://www.mkdocs.org/)-based static website to [GitHub Pages](https://pages.github.com/).
```

# "Deploy Website" workflow (MkDocs, Poetry)

Deploy a [MkDocs](https://www.mkdocs.org/)-based static website to [GitHub Pages](https://pages.github.com/).

This is the version of the workflow for projects using the [Poetry](https://python-poetry.org/) dependency management tool.

## Installation

### Workflow

Install the [`deploy-mkdocs-poetry.yml`](deploy-mkdocs-poetry.yml) GitHub Actions workflow to `.github/workflows/`

### Assets

- [`mkdocs.yml`](assets/mkdocs/mkdocs.yml) - base MkDocs configuration file.
  - Install to: repository root
- [`icon_mac_light.png`](assets/mkdocs/icon_mac_light.png) - Arduino logo for the website. **NOTE**: only for use in official Arduino projects. Community projects should use [the Community Logo](https://www.arduino.cc/en/Trademark/CommunityLogo).
  - Install to: `docs/img/`

### Dependencies

The website build dependencies are managed by [Poetry](https://python-poetry.org/).

Install Poetry by following these instructions:<br />
https://python-poetry.org/docs/#installation

If your project does not already use Poetry, you can initialize the [`pyproject.toml`](https://python-poetry.org/docs/pyproject/) file using these commands:

```
poetry init --python="^3.9" --dev-dependency="mkdocs@^1.2.1" --dev-dependency="mkdocs-material@^7.2.5" --dev-dependency="mdx_truly_sane_lists@^1.2"
poetry install
```

If already using Poetry, add the tool using this command:

```
poetry add --dev "mkdocs@^1.2.1" "mkdocs-material@^7.2.5" "mdx_truly_sane_lists@^1.2"
```

Commit the resulting `pyproject.toml` and `poetry.lock` files.

### Configuration

#### Workflow

The workflow is configured for repositories that host the website source content in a branch named `main`. If the project uses a different branch, adjust the `on.push.branches[]` value in `deploy-mkdocs-poetry.yml`.

#### MkDocs

Fill in all blank field in `mkdocs.yml` with the project-specific information.

Add entries for each website source file to the `nav` array in `mkdocs.yml`, or remove `nav` to have MkDocs auto-generate the navigation panel.

Reference: https://www.mkdocs.org/user-guide/configuration/

### Readme badge

Markdown badge:

```markdown
[![Deploy Website status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/deploy-mkdocs-poetry.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/deploy-mkdocs-poetry.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/deploy-mkdocs-poetry.yml/badge.svg["Deploy Website status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/deploy-mkdocs-poetry.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to deploy a MkDocs-based website to GitHub Pages

On every push to the repository's default branch, deploy the repository's MkDocs-based static website to GitHub Pages.
```

## PR message

```markdown
On every push to the repository's default branch, deploy the repository's [MkDocs](https://www.mkdocs.org/)-based static website to [GitHub Pages](https://pages.github.com/).
```

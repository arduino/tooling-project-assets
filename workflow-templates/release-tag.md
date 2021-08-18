# "Release" workflow

Make a [GitHub release](https://docs.github.com/en/github/administering-a-repository/releasing-projects-on-github/about-releases) with changelog on release [tag](https://git-scm.com/book/en/v2/Git-Basics-Tagging) push.

## Installation

### Workflow

Install the [`release-tag.yml`](release-tag.yml) GitHub Actions workflow to `.github/workflows/`

### Readme badge

Markdown badge:

```markdown
[![Release status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/release-tag.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/release-tag.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/release-tag.yml/badge.svg["Release status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/release-tag.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add GitHub Actions workflow to generate releases

On every push of a release tag (e.g., "1.2.3" or "v1.2.3") to the repository, create a GitHub release with a raw
changelog generated from the commit history since the last release tag.

Tags that contain a pre-release version will cause the GitHub release to be marked as a pre-release.
```

## PR message

```markdown
On every push of a release tag (e.g., `1.2.3` or `v1.2.3`) to the repository, create a [GitHub release](https://docs.github.com/en/github/administering-a-repository/releasing-projects-on-github/about-releases) with a raw [changelog generated](https://github.com/arduino/create-changelog) from the commit history since the last release tag.

Tags that contain a [pre-release version](https://semver.org/#spec-item-9) will cause the GitHub release to be marked as a pre-release.
```

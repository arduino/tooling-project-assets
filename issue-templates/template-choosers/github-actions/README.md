# Issue template chooser configuration for GitHub Actions actions

This is the issue template chooser configuration for use in [GitHub Actions action](https://docs.github.com/actions/concepts/workflows-and-actions/custom-actions) repositories.

## Installation

### Assets

- [`config.yml`](config.yml) - template chooser configuration file
  - Install to: `.github/ISSUE_TEMPLATE/`
- Issue templates - the chooser must be used in combination with issue templates or issue form configuration files. See the information about that [here](../../README.md).

### Configuration

Replace `TODO_REPO_OWNER/TODO_REPO_NAME` in the `contact_links[0].url` field of `config.yml`.

Add links for any additional relevant resources to the `contact_links[]` field of `config.yml`.

# General purpose issue template chooser configuration

This is the general purpose issue template chooser configuration suitable for use in any Arduino tooling project.

The template chooser is presented to the contributor when creating an issue in a repository that uses [issue templates](https://docs.github.com/en/communities/using-templates-to-encourage-useful-issues-and-pull-requests/configuring-issue-templates-for-your-repository).

This chooser can be customized by adding a [configuration file](https://docs.github.com/en/communities/using-templates-to-encourage-useful-issues-and-pull-requests/configuring-issue-templates-for-your-repository#configuring-the-template-chooser). This allows redirecting support requests via "Contact Links".

## Installation

### Assets

- [`config.yml`](config.yml) - template chooser configuration file
  - Install to: `.github/ISSUE_TEMPLATE/`
- Issue templates - the chooser must be used in combination with issue templates or issue form configuration files. See the information about that [here](../../README.md).

### Configuration

Replace `TODO_REPO_OWNER/TODO_REPO_NAME` in the `contact_links[0].url` field of `config.yml`.

Add links for any additional relevant resources to the `contact_links[]` field of `config.yml`.

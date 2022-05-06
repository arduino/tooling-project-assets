# Platform-dependent issue forms

These are the [GitHub issue form](https://docs.github.com/communities/using-templates-to-encourage-useful-issues-and-pull-requests/configuring-issue-templates-for-your-repository#creating-issue-forms) configuration files for platform-dependent projects.

## Installation

### Assets

- [`bug-report.md`](bug-report.yml) - issue form configuration for bug reports
  - Install to: `.github/ISSUE_TEMPLATE/`
- [`feature-request.md`](feature-request.yml) - issue form configuration for feature requests
  - Install to: `.github/ISSUE_TEMPLATE/`
- Template chooser - select the appropriate template chooser configuration for the project type from the [`template-choosers` folder](../../template-choosers) and follow the installation instructions provided there.

### Configuration

Replace the `TODO_*` placeholder text in the configuration files with the project-specific information.

## Commit message

```
Use form-based issue templates

High quality feedback via GitHub issues is a very valuable contribution to the project. It is important to make the
issue creation and management process as efficient as possible for the contributors, maintainers, and developers.

Issue templates are helpful to the maintainers and developers because it establishes a standardized framework for the
issues and encourages the contributors to provide the essential information.

The contributor is now presented with a web form when creating an issue. This consists of multi-line input fields that
have the same formatting, preview, and attachment capabilities as the standard GitHub Issue composer, in addition to
menus and checkboxes where appropriate.

The use of this form-based system should provide a much better experience for the contributors and also result in higher
quality issues by establishing a standardized framework for the issues and encouraging contributors to provide the
essential information.

A template chooser allows the contributor to select the appropriate template type, redirects support requests to the
appropriate communication channels via "Contact Links", and provides a prominent link to security policy to guide any
vulnerability disclosures.

The clear separation of the types of issues encourages the reporter to fit their report into a specific issue category,
resulting in more clarity. Automatic labeling according to template choice allows the reporter to do the initial
classification.
```

## PR message

```markdown
High quality feedback via GitHub issues is a very valuable contribution to the project. It is important to make the issue creation and management process as efficient as possible for the contributors, maintainers, and developers.

Issue templates are helpful to the maintainers and developers because it establishes a standardized framework for the issues and encourages the contributors to provide the essential information.

The contributor is now presented with [a web form](https://docs.github.com/communities/using-templates-to-encourage-useful-issues-and-pull-requests/configuring-issue-templates-for-your-repository#creating-issue-forms) when creating an issue. This consists of multi-line input fields that have the same formatting, preview, and attachment capabilities as the standard GitHub Issue composer, in addition to menus and checkboxes where appropriate.

The use of this form-based system should provide a better issue creation experience and result in higher quality issues by establishing a standardized framework for the issues and encouraging contributors to provide the essential information.

A [template chooser](https://docs.github.com/communities/using-templates-to-encourage-useful-issues-and-pull-requests/configuring-issue-templates-for-your-repository#configuring-the-template-chooser) allows the contributor to select the appropriate template type, redirects support requests to the appropriate communication channels via "Contact Links", and provides a prominent link to the security policy in order to guide any vulnerability disclosures.

The clear separation of the types of issues encourages the reporter to fit their report into a specific issue category, resulting in more clarity. Automatic labeling according to template choice allows the reporter to do the initial classification.
```

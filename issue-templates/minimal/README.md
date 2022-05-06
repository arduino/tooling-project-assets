# Minimal issue template

Even in cases where pre-filling the issue body with a template is not wanted, the GitHub template system has some very useful features:

- Template chooser allows redirecting support requests via "Contact Links", and also provides a prominent link to security policy to guide vulnerability disclosures.
- Encouraging the reporter to fit their report into a specific issue category results in more clarity.
- Automatic labeling according to template choice allows the reporter to do the initial classification.

This is the minimal issue template, applicable to any Arduino tooling project, in order to gain these benefits.

## Installation

### Assets

- [`bug-report.md`](bug-report.md) - bug report issue template
  - Install to: `.github/ISSUE_TEMPLATE/`
- [`feature-request.md`](feature-request.md) - feature request issue template
  - Install to: `.github/ISSUE_TEMPLATE/`
- Template chooser - select the appropriate template chooser configuration for the project type from the [`template-choosers` folder](../template-choosers) and follow the installation instructions provided there.

## Commit message

```
Add maintenance automation features from GitHub issue templates system

Although providing a structured template for filling information into an issue report is not appropriate for this
project, the GitHub issue template system offers some additional useful features for automating issue tracker
maintenance tasks:

- Template chooser allows redirecting support requests via "Contact Links", and also provides a prominent link to
  security policy to guide vulnerability disclosures.
- Encouraging the reporter to fit their report into a specific issue category results in more clarity.
- Automatic labeling according to template choice allows the reporter to do the initial classification.

This minimal issue template system provides these benefits without making any changes to the actual issue writing
process.
```

## PR message

```markdown
Although providing a structured template for filling information into an issue report is not appropriate for this project, the [GitHub issue template](https://docs.github.com/communities/using-templates-to-encourage-useful-issues-and-pull-requests/about-issue-and-pull-request-templates) system offers some additional useful features for automating issue tracker maintenance tasks:

- [Template chooser](https://docs.github.com/communities/using-templates-to-encourage-useful-issues-and-pull-requests/configuring-issue-templates-for-your-repository#configuring-the-template-chooser) allows redirecting support requests via "Contact Links", and also provides a prominent link to
  security policy to guide vulnerability disclosures.
- Encouraging the reporter to fit their report into a specific issue category results in more clarity.
- Automatic [labeling](https://docs.github.com/issues/using-labels-and-milestones-to-track-work/managing-labels) according to template choice allows the reporter to do the initial classification.

This minimal issue template system provides these benefits without making any changes to the actual issue writing process.
```

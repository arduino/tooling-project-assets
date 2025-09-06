# Dependabot for GitHub Actions

Dependabot can be used to check for outdated action versions used in the repository's GitHub Actions workflows:

https://docs.github.com/code-security/dependabot/working-with-dependabot/keeping-your-actions-up-to-date-with-dependabot

## Instructions

Just copy [this `dependabot.yml` file](dependabot.yml) to the `.github/` folder of the target repository (or add the entry if the repository already has a `.github/dependabot.yml`) and everything else is handled automatically.

### Note

Dependabot's PRs will occasionally propose to pin to the patch version of the action (e.g., updating `uses: foo/bar@v1` to `uses: foo/bar@v2.3.4`). When the action author has [provided a major version ref](https://docs.github.com/actions/concepts/workflows-and-actions/custom-actions#using-release-management-for-actions), use that instead (e.g., `uses: foo/bar@v2`). Once the major version has been updated in the workflow, Dependabot should not submit an update PR again until the next major version bump.

So even when the PRs from Dependabot are not exactly correct, they still have value in bringing the maintainer's attention to the fact that the action version in use is outdated. The effort needed to manually adjust the ref when this happens is trivial.

Dependabot will automatically close its PR once the workflow has been updated.

## Commit message

```
Configure Dependabot to check for outdated actions used in workflows

Dependabot will periodically check the versions of all actions used in the repository's workflows. If any are found to
be outdated, it will submit a pull request to update them.

NOTE: Dependabot's PRs will occasionally propose to pin to the patch version of the action (e.g., updating
`uses: foo/bar@v1` to `uses: foo/bar@v2.3.4`). When the action author has provided a major version ref, use that instead
(e.g., `uses: foo/bar@v2`). Dependabot will automatically close its PR once the workflow has been updated.

More information:
https://docs.github.com/code-security/dependabot/working-with-dependabot/keeping-your-actions-up-to-date-with-dependabot
```

## PR message

```Markdown
Dependabot will periodically check the versions of all actions used in the repository's workflows. If any are found to be outdated, it will submit a pull request to update them.

NOTE: Dependabot's PRs will occasionally propose to pin to the patch version of the action (e.g., updating `uses: foo/bar@v1` to `uses: foo/bar@v2.3.4`). When the action author has [provided a major version ref](https://docs.github.com/actions/concepts/workflows-and-actions/custom-actions#using-release-management-for-actions), use that instead (e.g., `uses: foo/bar@v2`). Once the major version has been updated in the workflow, Dependabot should not submit an update PR again until the next major version bump.

So even when the PRs from Dependabot are not exactly correct, they still have value in bringing the maintainer's attention to the fact that the action version in use is outdated. Dependabot will automatically close its PR once the workflow has been updated.

More information:
https://docs.github.com/code-security/dependabot/working-with-dependabot/keeping-your-actions-up-to-date-with-dependabot
```

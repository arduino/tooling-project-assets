# Outdated GitHub Actions action version check

Dependabot is used to [check for outdated action versions](https://docs.github.com/en/github/administering-a-repository/keeping-your-actions-up-to-date-with-dependabot) used in the template workflows.

The files under `/workflow-templates/dependabot/workflow-template-copies/.github/workflows/` are duplicates of the files under `/workflow-templates/`. This is done as a workaround for the lack of support for defining exact workflow folders in the Dependabot configuration (it always checks the YAML files in the `.github/workflows/` subfolder of the path specified via the `updates[].directory` configuration key of [`dependabot.yml`](https://docs.github.com/en/github/administering-a-repository/configuration-options-for-dependency-updates#about-the-dependabotyml-file).

So do not merge the PRs from Dependabot for the files under `/workflow-templates/dependabot-copies/.github/workflows/`. The equivalent workflow templates directly under `/workflow-templates/` must be updated instead. The Dependabot PRs for these files are used only as notifications of available action updates.

Dependabot's PRs will occasionally try to pin to the patch version of the action (e.g., updating `uses: foo/bar@v1` to `uses: foo/bar@v2.3.4`). When the action author has [provided a major version ref](https://docs.github.com/en/actions/creating-actions/about-actions#using-release-management-for-actions), use that instead (e.g., `uses: foo/bar@v2`). Once the major version has been updated in the workflow, Dependabot should not submit an update PR again until the next major version bump.

Dependabot will automatically close its PR once the workflow has been updated.

Run `task fix` after making any changes to the workflow templates under `/workflow-templates/`. That script will synchronize the copies. The repository has a CI workflow to check the sync.

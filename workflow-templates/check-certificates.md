# "Check Certificates" workflow

Workflow file: [check-certificates.yml](check-certificates.yml)

Check code signing certificates for problems or pending expiration.

## Setting up Slack webhook

1. Open https://arduino.slack.com/apps/A0F7XDUAZ-incoming-webhooks
1. Click the "Add to Slack" button
1. From the "Post to Channel" menu, select the appropriate channel.
1. Click the "Add Incoming WebHooks integration"
1. From the "Customize Icon" section, click the "Choose an emoji" button
1. Enter `:warning:`
1. Click the "Save Settings" button
1. Copy the text in the "Webhook URL" field
1. Save the webhook URL to a [repository secret](https://docs.github.com/en/actions/reference/encrypted-secrets#creating-encrypted-secrets-for-a-repository) named `SLACK_WEBHOOK`
   - Make sure there is no newline at the end of the secret, otherwise the slack post process will fail.

## Readme badge

Markdown badge:

```markdown
[![Check Certificates status](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-certificates.yml/badge.svg)](https://github.com/REPO_OWNER/REPO_NAME/actions/workflows/check-certificates.yml)
```

Replace the `REPO_OWNER` and `REPO_NAME` placeholders in the URLs with the final repository owner and name ([example](https://raw.githubusercontent.com/arduino-libraries/ArduinoIoTCloud/master/README.md)).

---

Asciidoc badge:

```adoc
image:https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-certificates.yml/badge.svg["Check Certificates status", link="https://github.com/{repository-owner}/{repository-name}/actions/workflows/check-certificates.yml"]
```

Define the `{repository-owner}` and `{repository-name}` attributes and use them throughout the readme ([example](https://raw.githubusercontent.com/arduino-libraries/WiFiNINA/master/README.adoc)).

## Commit message

```
Add CI workflow to check for problems with signing certificates

The workflow runs on a schedule to check for problems with the signing certificates and notify if any are found.
If a problem is found, a notification is posted to the Slack channel configured via the SLACK_WEBHOOK secret.
```

## PR message

```markdown
The workflow runs on a schedule to check for problems with the signing certificates and notify if any are found. If a problem is found, a notification is posted to the Slack channel configured via the `SLACK_WEBHOOK` secret.
```

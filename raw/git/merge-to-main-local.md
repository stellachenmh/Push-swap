# Method 1: Merge Locally and Push (Fastest)

> Source: local file stella WIP/merge_to_main.md
> Collected: 2026-10-20
> Published: Unknown

Use this method if you have direct write access to the `main` branch and don't require a code review.

## 1. Commit your work on your current feature branch

```bash
git add .
git commit -m "Your commit message"
```

## 2. Switch to your local `main` branch

```bash
git checkout main
```

## 3. Pull the latest changes from the remote repository to ensure your local `main` is up-to-date

```bash
git pull origin main
```

## 4. Merge your feature branch into `main`

```bash
git merge <your-branch-name>
```

## 5. Push the updated `main` branch to the remote repository (e.g., GitHub, GitLab)

```bash
git push origin main
```

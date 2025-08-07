# Enhanced Git Cheat Sheet

This cheat sheet expands on the essentials of Git, including advanced commands, best practices, and additional tips for efficient version control. Commands are organized by workflow stage, with examples and explanations for clarity.

---

## Setup & Configuration
Configure Git settings and verify your setup.

```sh
git config --global user.name "Your Name"               # Set your name
git config --global user.email "your.email@example.com" # Set your email
git config --global core.editor "nano"                  # Set default editor (e.g., nano, vim)
git config --global init.defaultBranch main             # Set default branch name to "main"
git config --list                                       # View all configurations
git config --global alias.st status                     # Create alias (e.g., `git st` for `git status`)
```

**Tip:** Use `git config --global --edit` to open the config file in your editor for bulk changes.

---

## Initializing & Cloning Projects
Start or replicate repositories.

```sh
git init                            # Initialize a new Git repository in current directory
git init --bare                     # Create a bare repository (no working tree)
git clone <url>                     # Clone a repository from a URL
git clone <url> <directory>         # Clone into a specific directory
git clone --branch <branch> <url>   # Clone a specific branch
```

**Example:**
```sh
git clone https://github.com/user/repo.git my-project
```

**Tip:** Use `git clone --depth 1 <url>` for a shallow clone to save time on large repositories.

---

## Snapshotting Changes
Track and commit changes to your repository.

```sh
git status                          # Show working directory and staging area status
git add <file>                      # Stage a specific file
git add -A                          # Stage all changes (new, modified, deleted)
git add -u                          # Stage modified and deleted files only
git commit -m "Descriptive message" # Commit staged changes with a message
git commit -a -m "message"          # Stage and commit all tracked files
git diff                            # Show unstaged changes
git diff --staged                   # Show staged changes
git diff <commit1> <commit2>        # Compare two commits
```

**Example:**
```sh
git add src/main.py
git commit -m "Add user authentication logic"
```

**Tip:** Use `git commit --amend` to modify the last commit message or add more changes.

---

## Branching & Merging
Manage branches for parallel development.

```sh
git branch                          # List all branches (current branch marked with *)
git branch <name>                   # Create a new branch
git checkout <name>                 # Switch to an existing branch
git checkout -b <name>              # Create and switch to a new branch
git merge <branch>                  # Merge specified branch into current branch
git merge --no-ff <branch>          # Merge with no fast-forward (creates merge commit)
git branch -d <name>                # Delete a merged branch
git branch -D <name>                # Force delete an unmerged branch
git rebase <branch>                 # Rebase current branch onto another branch
```

**Example:**
```sh
git checkout -b feature/login
git commit -m "Add login page"
git checkout main
git merge feature/login
```

**Tip:** Use `git rebase -i <commit>` for interactive rebasing to squash or reorder commits.

---

## Remote Repositories
Work with remote repositories (e.g., GitHub, GitLab).

```sh
git remote -v                       # List remote repositories
git remote add origin <url>         # Add a remote repository
git remote set-url origin <url>     # Update remote URL
git push -u origin <branch>         # Push branch to remote and set upstream
git push                            # Push commits to default remote/branch
git push --force                    # Force push (use with caution)
git pull                            # Fetch and merge from remote
git pull --rebase                   # Fetch and rebase instead of merge
git fetch                           # Fetch changes without merging
git fetch --prune                   # Remove deleted remote branches
```

**Example:**
```sh
git remote add origin https://github.com/user/repo.git
git push -u origin main
```

**Tip:** Use `git push --force-with-lease` instead of `--force` to avoid overwriting others' work.

---

## Undoing Changes
Revert or undo changes safely.

```sh
git checkout -- <file>              # Discard changes in working directory
git restore <file>                  # Alternative to checkout (Git 2.23+)
git reset HEAD <file>               # Unstage a file
git reset --soft <commit>           # Reset to commit, keep changes staged
git reset --hard <commit>           # Reset to commit, discard all changes (DANGEROUS)
git revert <commit>                 # Create a new commit to undo changes
git clean -fd                       # Remove untracked files and directories
```

**Example:**
```sh
git reset HEAD src/main.py
git checkout -- src/main.py
```

**Tip:** Use `git reflog` to recover lost commits after a reset.

---

## Viewing History
Inspect commit history and changes.

```sh
git log                             # Show detailed commit history
git log --oneline                   # Show compact commit history
git log --graph --all               # Show branch graph for all branches
git log --author="Name"             # Filter commits by author
git log --grep="keyword"            # Filter commits by message
git show <commit>                   # Show details of a specific commit
git blame <file>                    # Show who last modified each line
```

**Example:**
```sh
git log --oneline --graph --all
```

**Tip:** Use `git log -p` to see the diff for each commit.

---

## Stashing Changes
Temporarily save and restore changes.

```sh
git stash                           # Stash changes in working directory
git stash save "message"            # Stash with a custom message
git stash list                      # List all stashes
git stash apply                     # Apply latest stash (keeps stash)
git stash pop                       # Apply and remove latest stash
git stash drop stash@{n}            # Remove a specific stash
git stash clear                     # Remove all stashes
```

**Example:**
```sh
git stash save "WIP: incomplete feature"
git stash pop
```

**Tip:** Use `git stash apply stash@{n}` to apply a specific stash by index.

---

## Tagging
Mark specific points in history (e.g., releases).

```sh
git tag <tagname>                   # Create a lightweight tag
git tag -a <tagname> -m "message"   # Create an annotated tag
git tag -l                          # List all tags
git show <tagname>                  # Show tag details
git push origin <tagname>           # Push a tag to remote
git push origin --tags              # Push all tags to remote
git tag -d <tagname>                # Delete a tag locally
git push origin --delete <tagname>  # Delete a tag remotely
```

**Example:**
```sh
git tag -a v1.0.0 -m "Release 1.0.0"
git push origin v1.0.0
```

**Tip:** Annotated tags (`-a`) store metadata and are preferred for releases.

---

## Advanced Commands
Power-user commands for specific scenarios.

```sh
git cherry-pick <commit>            # Apply a specific commit to current branch
git rebase -i <commit>              # Interactive rebase to edit/squash commits
git bisect start                    # Start binary search for a bug
git bisect good/bad                 # Mark commits as good or bad
git bisect reset                    # End bisect session
git reflog                          # Show reference log (recover lost commits)
git worktree add <path> <branch>    # Create a new worktree for a branch
```

**Example:**
```sh
git cherry-pick abc123
git rebase -i HEAD~3
```

**Tip:** Use `git bisect` to efficiently find the commit introducing a bug.

---

## Best Practices
- **Commit Often:** Small, focused commits are easier to review and revert.
- **Write Clear Messages:** Use imperative mood (e.g., "Add feature" not "Added feature").
- **Branch Strategically:** Use feature branches for new work, keep `main` stable.
- **Pull Before Push:** Always `git pull --rebase` to avoid merge conflicts.
- **Backup Work:** Push to a remote regularly to avoid data loss.
- **Review Changes:** Use `git diff` and `git status` before committing.

---

## Quick Tips
- Run `git status` frequently to track your working directory.
- Use `.gitignore` to exclude files (e.g., `node_modules/`, `*.log`).
- Leverage aliases for repetitive commands (e.g., `git config --global alias.co checkout`).
- Explore GUI tools like GitKraken or Sourcetree for visual workflows.
- Read the [Official Git Documentation](https://git-scm.com/doc) for in-depth guides.
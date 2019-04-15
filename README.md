# Git Flow

> Author(s): Andrew Lvovsky ([@borninla](https://github.com/borninla))

For most of our professional careers in the industry, we work on projects with many individuals. When working on a project with a team (like the upcoming R'Shell), it's important to communicate what part is currently being worked on.

## An Example of a Merge Conflict
Let's say Alice and Bob are concurrently working on the same feature of a project. They both pull the most recent commit in their development branch and start coding away. However, they didn't properly communicate on what part of the feature they are working on. Because of this, Alice edits over existing code, while Bob leaves that code intact. Alice finishes first and proceeds to commit and push her changes (without any error, since she made the commit before Bob). When Bob finishes his part, he commits and tries to push, but gets a merge conflict in the process.

## How to Avoid Merge Conflicts
According to [GitHub's own article](https://help.github.com/en/articles/resolving-a-merge-conflict-using-the-command-line), merge conflicts occur when separate changes are made to the same line of a file by two or more people. They can also occur when one person edits a file while another person deletes that file off the same commit.

As stated earlier, communication with team members are key when working on any project. One way to avoid conflicts is to make sure that every team member is editing unique parts of the project. In the event the same file needs to be edited by multiple people, branching seems like the best bet.

## The Importance of Effective Branching
In the Git lab, we learned that branching is used when developers want to change code without having conflicts commit after commit. When working on a team, it is wise to separate what someone is working on by making a branch unique to that addition or edit. When that team member finishes their part, they can then merge back into the master or main development branch.

Each partner should now create a branch from the master branch. Both partners should title their branches as such, respectively:

```
$ git branch <partner-1-github-username>/add-fib-func
$ git branch <partner-2-github-username>/add-main-prompt
```

Make sure to checkout the branches after creating them.

Partner 1 should add the following exchange to the main function in `main.cpp`:

```
#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    cout << "We should probably have a prompt for the function here." << endl;
    cout << "Leaving this job for Partner 2. Have fun!" << endl;
    
    return 0;
}
```

Partner 2 should add the following user prompt in the main function in `main.cpp`:

```
#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n;
    cout << "Please enter a number: ";
    cin >> n;
    cout << "The nth term of the fibonacci sequence is " << fibonacci(n) << endl;
    
    return 0;
}
```

Commit and push your changes to your respective branches.

> Note: Since these branches were made locally and need to be pushed up to GitHub, you will be prompted to run `git push --set-upstream origin <branch name>` when pushing a branch for the first time.

Each partner should also refresh their local git by running `git fetch`. This will update your local repository so that the other partner's branch will show up.

Before merging the branches, it is good practice to open a pull request that can be reviewed by your team members.

## Pull Requests
Pull requests (PRs) exist as a way to review a development branch before merging into a stable branch. When the author of the development branch is finished with a part, they open a request through GitHub. They specify which branch they'd like to merge into and describe the changes they made.

Let's try doing this now. Both partners should open up their GitHub repository to prepare the PR. 

### Creating a Pull Request

Partner 1 should press on the branch dropdown menu and select `<partner-1-github-username>/add-fib-func`. Next, click on "New pull request". This will bring up the editing screen for the PR. Title it `Fibonacci Function` and leave a brief description of what is being added. In most cases, a description should be well-detailed so the reviewer can easily understand. Next, added a reviewer by clicking on the "Reviewers" section to the right of the description box. Search Partner 2's username and click on their username. This will assign Partner 2 to review the PR. Under "Reviewers", click on "Assignees", then search and select Partner 1's username. This denotes that Partner 1 is in charge of the branch that is being pulled in. Under "Assignees", select "Labels" and choose "enhancement" (you can also create a custom label by clicking on "edit labels" on the bottom of the dropbown menu). 

The rest of the sections, Projects and Milestones, don't need to be picked. Projects are useful for when developers need to split a large project into smaller projects, and Milestones are useful for agile development.

Once done finalizing the PR, click on "Create pull request".

Partner 2 should follow the same steps above, except by selecting `<partner-2-github-username>/add-main-prompt` from the branch dropdown menu. Also, title it `Main Prompt`. Make sure to choose Partner 1 as the reviewer and Partner 2 as the assignee.

### Reviewing a Pull Request

Partner 2 should now review Partner 1's PR. Navigate to the "Pull requests" tab and click on `Fibonacci Function`. From here, you can review comments made about the PR, all commits associated with that PR, and what changed within the files.

Near the bottom, you should see a green checkmark. This means GitHub found no possible merge conflicts. Go ahead and press "Merge pull request". This completes the merge from the `<partner-1-github-username>/add-fib-func` branch to the master branch. You are now given the option to delete the branch. It's nice to keep repositories neat and tidy, so go ahead and delete the branch.

Partner 1 should navigate to the "Pull requests" tab and click on `Main Prompt`. Unlike the first PR, this one has a merge conflict.

<img src="https://github.com/cs100/template-lab-XX-git-flow/blob/dev/images/resolve-conflicts.png?raw=true" width="600">

Let's resolve that now. Partner 1 should go back to their local environment and type `git fetch origin` to fetch and store all the remote updates locally. Next, type `git checkout -b <partner-1-github-username>/add-main-prompt origin/<partner-1-github-username>/add-main-prompt`, which will copy Partner 2's remote branch into a new local branch and check it out. Finally, type `git merge master` to merge the current branch you checked out into master. You should see something like below:

```
Auto-merging main.cpp
CONFLICT (content): Merge conflict in main.cpp
Automatic merge failed; fix conflicts and then commit the result.
```
If you open `main.cpp` in a text editor, you should see some lines that include `<<<<<<< HEAD`, `=======`, and `>>>>>>> master`. 

<img src="https://github.com/cs100/template-lab-XX-git-flow/blob/dev/images/conflict.png?raw=true" width="600">

Everything past `<<<<<<< HEAD` and before `=======` is the new code coming in from the branch being merged, while everything past `=======` and before `>>>>>>> master` is existing code from the master branch (the branch that is being merged into). We'd like to accept the new code, so go ahead and delete everything past `=======` and before `>>>>>>> master`. Make sure to also delete these indicators, or you will get obvious compilation errors.

Once you are done, be sure to commit and push as usual.

Partner 1 should now refresh the `Main Prompt` PR on GitHub. Notice that every commit made in the branch should appear within the PR. There should no longer be any merge conflicts, so go ahead and press "Merge pull request" and repeat the same process as stated above.

## Reverting Commits

Throughout the development process, there are times where new commits may introduce problems in existing code. Luckily, `git revert` exists.

Let's say you push a commit that breaks something. To revert back to the last commit, type the following command.

```
git revert HEAD
```

This will create a new commit that is left off at the last commit. To revert to 2 or more commits down the chain, replace `HEAD` with the commit reference. 

## Code Reviews

## Tagging

## Issue Tracking

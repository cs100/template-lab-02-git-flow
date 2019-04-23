# GitHub Flow

> Author(s): Andrew Lvovsky ([@borninla](https://github.com/borninla))

For most of our professional careers in the industry, we work on projects alongside many individuals. Everyone has their own style of coding, like choosing between tabs or spaces. While agreeing on a certain convention is nice, efficient project workflow is an important methodology to follow. When working on a project with a team (like the upcoming R'Shell), it's important to communicate what part is currently being worked on.

Many [Git workflows](https://www.endpoint.com/blog/2014/05/02/git-workflows-that-work) exist today, and they all have their pros and cons. However, GitHub flow is one of the simplest to learn and is our preferred method. A brief overview of GitHub flow is found in the diagram below..

<img src="https://github.com/cs100/template-lab-XX-git-flow/blob/dev/images/github-flow.png?raw=true" width="600">

Source: [GitHub Guides](https://guides.github.com/introduction/flow/)

## The Importance of Effective Branching
In the Git lab, we learned that branching is used when developers want to change code without having conflicts commit after commit. When working on a team, it is wise to separate what someone is working on by making a branch unique to that addition or edit. When that team member finishes their part, they can then merge back into the master or main development branch.

Each partner should now create a branch from the master branch. Both partners should title their branches as such, respectively:

```
$ git branch <partner-1-github-username>/add-fib-func
$ git branch <partner-2-github-username>/add-main-prompt
```

Make sure to checkout the branches after creating them.

### The First Branch

We have provided a `main.cpp` file for editing.

Partner 1 should add the following exchange to the main function in `main.cpp`:

```c++
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

### Issue Tracking

This is a good time to learn about the Issues tab under every GitHub repository. 

We see that Partner 1 added the fibonacci function, but there is no way to use it in main. Let's fix that! 

Partner 2 should go to the Issues tab and open a new issue. Title it "Fibonacci Not Outputting". On the right, assign Partner 2 (through their GitHub) and label the issue "invalid". Add a description you see fit, then submit the issue. We'll come back to this later.

### The Second Branch

Partner 2 should add the following user prompt in the main function in `main.cpp`:

```c++
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

## Code Reviews

Throughout development, team members will most likely be working on integrating features into existing code. To help understand what is being added, code reviews are usually held with the team or scrum master to better explain the addition. The traditional way is to meet and work through explaining every critical section of code, but doing this through pull requests is also acceptable.

## Pull Requests
Pull requests (PRs) exist as a way to review a development branch before merging into a stable branch. When the author of the development branch is finished with a part, they open a request through GitHub. They specify which branch they'd like to merge into and describe the changes they made.

Let's try doing this now. Both partners should open up their GitHub repository to prepare the PR. 

### Creating a Pull Request

Partner 1 should press on the branch dropdown menu and select `<partner-1-github-username>/add-fib-func`. Next, click on "New pull request". This will bring up the editing screen for the PR. Title it `Fibonacci Function` and leave a brief description of what is being added. In most cases, a description should be well-detailed so the reviewer can easily understand. Next, added a reviewer by clicking on the "Reviewers" section to the right of the description box. Search Partner 2's username and click on their username. This will assign Partner 2 to review the PR. Under "Reviewers", click on "Assignees", then search and select Partner 1's username. This denotes that Partner 1 is in charge of the branch that is being pulled in. Under "Assignees", select "Labels" and choose "enhancement" (you can also create a custom label by clicking on "edit labels" on the bottom of the dropbown menu). 

The rest of the sections, Projects and Milestones, don't need to be picked. Projects are useful for when developers need to split a large project into smaller projects, and Milestones are useful for agile development.

Once done finalizing the PR, click on "Create pull request".

Partner 2 should follow the same steps above, except by selecting `<partner-2-github-username>/add-main-prompt` from the branch dropdown menu. Also, title it `Main Prompt`. Make sure to choose Partner 1 as the reviewer and Partner 2 as the assignee.

### Issue Tracking Strikes Back!

Remember that issue you made? Go back to it and update it by writing `Fixed in #2` as a comment. #2 should hyperlink to the PR Partner 2 made that fixes that issue. Once that comment is made, go ahead and press on "Close issue".

### Reviewing a Pull Request

Partner 2 should now review Partner 1's PR. Navigate to the "Pull requests" tab and click on `Fibonacci Function`. From here, you can review comments made about the PR, all commits associated with that PR, and what changed within the files.

Near the bottom, you should see a green checkmark. This means GitHub found no possible merge conflicts. Go ahead and press "Merge pull request". This completes the merge from the `<partner-1-github-username>/add-fib-func` branch to the master branch. You are now given the option to delete the branch. It's nice to keep repositories neat and tidy, so go ahead and delete the branch.

Partner 1 should navigate to the "Pull requests" tab and click on `Main Prompt`. Unlike the first PR, this one has a merge conflict.

<img src="https://github.com/cs100/template-lab-XX-git-flow/blob/dev/images/resolve-conflicts.png?raw=true" width="600">

#### Fixing a Merge Conflict
Let's resolve that now. Partner 1 should go back to their local environment and type `git fetch origin` to fetch and store all the remote updates locally. Next, type `git checkout -b <partner-1-github-username>/add-main-prompt origin/<partner-1-github-username>/add-main-prompt`, which will copy Partner 2's remote branch into a new local branch and check it out. Finally, type `git merge master` to merge the current branch you checked out into master. You should see something like below:

```
Auto-merging main.cpp
CONFLICT (content): Merge conflict in main.cpp
Automatic merge failed; fix conflicts and then commit the result.
```
If you open `main.cpp` in a text editor, you should see some lines that include `<<<<<<< HEAD`, `=======`, and `>>>>>>> master`. 

<img src="https://github.com/cs100/template-lab-XX-git-flow/blob/dev/images/conflict.jpg?raw=true" width="600">

Everything past `<<<<<<< HEAD` and before `=======` is the new code coming in from the branch being merged, while everything past `=======` and before `>>>>>>> master` is existing code from the master branch (the branch that is being merged into). We'd like to accept the new code, so go ahead and delete everything past `=======` and before `>>>>>>> master`. Make sure to also delete these indicators, or you will get obvious compilation errors.

Once you are done, be sure to commit and push as usual.

Partner 1 should now refresh the `Main Prompt` PR on GitHub. Notice that every commit made in the branch should appear within the PR. There should no longer be any merge conflicts, so go ahead and press "Merge pull request" and repeat the same process as stated above.

## Tagging

Often, you’ll want to tag certain git commits because they are special. The most common reason to tag a commit in git is to tag it as a beta or release version, especially when using semantic versioning schemes. Let's assume that our code is now ready for release as a v1.0.0 and tag it as such.

```
$ git tag -a v1.0.0 -m “Initial release”
```

The -m in this case works the same as it does when performing a commit, allowing us to add a message but bypassing the editor to do so. Note that if you wanted to tag a commit besides the current commit you would need to add the commit hash after the version number (but before the message). Normally a 1.0.0 release would have lots of additional notes on the current state of the software, but this is just an example. These tagged versions are stored in a special section of the repository on GitHub along with compressed versions of the source files to make public releases easier.

## Reverting Commits

Throughout the development process, there are times where new commits may introduce problems in existing code. For these situations, git handles reversion quite well.

Let's say you push a commit that breaks something. To revert back to the last commit, type the following command.

```
git revert HEAD
```

This will create a new commit that is left off at the last commit. To revert to 2 or more commits down the chain, replace `HEAD` with the commit reference (the long string of characters that identify each commit).

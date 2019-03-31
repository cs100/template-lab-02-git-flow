# Git Flow

> Author(s): Andrew Lvovsky ([@borninla](https://github.com/borninla))

When working on a project with a team (like the upcoming R'Shell), it's important to communicate who is working on what.

## An Example of a Merge Conflict
Let's say Alice and Bob are concurrently working on the same feature of a project. They both pull the most recent commit in their development branch and start coding away. However, they didn't properly communicate on what part of the feature they are working on. Because of this, Alice edits over existing code, while Bob leaves that code intact. Alice finishes first and proceeds to commit and push her changes (without any error). When Bob finishes his part, he commits and tries to push, but gets a merge conflict in the process.

## How to Avoid Merge Conflicts
According to [GitHub's own article](https://help.github.com/en/articles/resolving-a-merge-conflict-using-the-command-line), merge conflicts occur when seperate changes are made to the same line of a file by two or more people. They can also occur when one person edits a file while another person deletes that file off the same commit.

As stated earlier, communication with team members key when working on any project. One way to avoid conflicts is to make sure that every team member is editing unique parts of the project. In the event the same file needs to be edited by multiple people, branching seems like the best bet.

## The Importance of Effective Branching
In the Git lab, we learned that branching is used when developers want to change code without having conflicts commit after commit. When working on a team, it is wise to seperate what someone is working on by making a branch unique to that addition or edit. When that team member finishes their part, they can then merge back into the master or main development branch. Before merging yourself, it is suggested to open a pull request that can be reviewed by your team members.

## Pull Requests

## Code Reviews

## Tagging

## Issue Tracking

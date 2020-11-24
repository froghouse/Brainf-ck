# Branching strategy

## Overview
1. The master branch is holy, only merge working code that is to be released as the current version.
2. A new branch should be created for a new version of the code.
3. A new branch should be created for a new feature of the code.
4. A new branch should be created for local development of the code.

![Branching Strategy](https://i.imgur.com/b3WtqmL.png Branching Strategy)

The above ASCII art describes visually how branching should look.
Each commit to the master increases the version number (e.g. 1.0 to 2.0)
Each commit to the new version should carry the next version number (Master is on 1.0, then new version is on 2.0)
A new feature should carry the next minor number in order (New version is on 2.0, the new feature is on 2.1)
The local development carries an even smaller version number (New feature is on 2.1, the local development is on 2.1.1)
The version number is enherited downwards until master.

## Naming branches
Master should always be called master.
New versions should be named Next_Version_[major] (e.g. Next_Version_2)
New features should be named Feature_Version_[major]_[minor] (e.g. Feature_Version_2_1)
Local dev branches should be named [Programmer first name]_[First letter of last name]_[major]_[minor]_[sub] (e.g. Tomas_L_2_1_1)

## Hotfixes
Hotfixes should be branched from Master, numbered in order, and named after the bug report it is addressing (e.g. Hotfix_1_e32ff)
Local dev on hotfixes should be it's own branch and named Hotfix_[hotfix id]_[bug id]_[Programmer first name]_[First letter of last name] (e.g. Hotfix_1_e32ff_Tomas_L)

# Shows Git branch name in prompt.
parse_git_branch() {
  git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/ (\1)/'
}
# Show User @ Name (still with git branch name)
# export PS1="\u@\h \W\[\033[32m\]\$(parse_git_branch)\[\033[00m\] $ "
# Or hide User @ Name (still with git branch name)
export PS1="\u:\w\[\033[32m\]\$(parse_git_branch)\[\033[00m\]$ "
export TERM=xterm-256color
eval "$(starship init bash)"
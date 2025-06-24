# PIPEX

Reproduction of shell piping < file1 cmd1 | cmd2 > file2 in C (42 Madrid project).

## 📦 Requirements

- Linux or macOS  
- make, gcc  

---

## 🚀 Installation & Compilation

    git clone https://github.com/Albertiito13/pipex.git
    cd pipex
    make

🏁 Usage

    ./pipex infile "cmd1 args" "cmd2 args" outfile

This mimics:

    < infile cmd1 args | cmd2 args > outfile

🎯 How It Works

  Open infile for reading, outfile for writing.

  Create a pipe and fork a child process.

  Child process:

   Redirects infile → stdin with dup2.

   Pipes output → pipe write end.

   Executes cmd1 via execve.

  Parent process:
  
   Redirects pipe read end → stdin.

   Redirects stdout → outfile.

   Executes cmd2 via execve.

⚠️ Error Handling & Good Practices

  Check return values of open, pipe, fork, dup2, execve, etc.

  Use perror() for stderr messages.

  Close unused file descriptors to avoid resource leaks.

  Use wait() or waitpid() to avoid zombie processes.

📚 Learnings & Concepts Covered

  UNIX pipes with pipe()

  Process creation via fork()

  File descriptor redirection using dup2()

  Command execution through execve()

  Robust error and resource management

✅ Example

    printf "Hello\nWorld\n" > infile
    ./pipex infile "grep Hello" "wc -l" outfile
    cat outfile  # Output: 1

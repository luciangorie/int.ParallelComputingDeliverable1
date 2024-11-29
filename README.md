# int.ParallelComputingDeliverable1
here is the repository for int.PARCO D1

You can find:

- directory for tests results and analysis attached to the document
- official document IEEE submitted via e-mail









The main can also be created autonomously by the user that can customize an execution for different needs.
be aware that:

-transposing more times the same matrix can give misleading results as data could already be in the cache or in faster  memory.
-the program can run everywhere, but not every N for matrix size could work in every system (consider to calculate memory usage by calculating N*N*4 bytes for each matrix present in the code).
. Timers are effective but do not perform well on very small amounts of time
-include all libraries reported
-take in consideration to follow the general idea that checkSym() should be used to avid matrix transposition, as a symmetric matrix is equal to its transposal. The reccomended order is: create new Timer(), allocate and create matrix/ matrices, start timer, check symmetry, stop timer, print timer, if symmetric end program, if not symmetric start timer again compute the tramspose, stop timer and check result, if check is correctly complete store the transpose in a new matrix.

// Greedy is nothing bs usse time pr wo kro jisse appropriate result k side jaye and
//  profit maximise ho jaye....iske liye sort krke do ya bina sort k pointer se choose kro it's a choice
//  but greedy mein overall yhi krrhe ki hum usse time most optimal choose krrhe
//  Greedy works jb choice baht jda ho to harr choice nhi dekh skte ho to greedy lgado

// An easy way to tell if a LeetCode problem expects DP is if the constraints say the array won't be larger than 200 or something suspiciously small, but in real-world situations a problem might need DP if current decisions affect future decisions and multiple decisions can lead to the same state.

// For the flowerpot example, let's say for [0,0,0,1,0,0], n=1, placing the flower at index 0 or 1 has no effect on the outcome or the ability to place a flower at index 5, so the lack of decision making implies greedy will work.

// Greedy - If you get optimal solution take it now, don't think much. (chahe future me koi optimal mile ya na mile, jo abhi mil rha lete jao)
// DP - Hey, if you get optimal solution, don't take it, first check if you are getting more optimal soln or not in coming path. ( aur ydi nhi milta hai to backtrack kro aur dusra path pakdo)

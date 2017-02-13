# Reading
## Written sprint reflection

During this sprint, I set out to get a good understanding of C. I think this has gone fairly well, I feel more comfortable program in C and can typically complete all of the exericises and questions with no problems. I do tend to struggle the most on learning new libraries and understanding the document associated with it. I think it would be helpful for me moving forward to comment all of the new code that I write to the fullest level so that I understand exactly what is happening on the library level.

I think that on a teaming level our group is doing well. We have been taking on most of the eduScrum ceremonies (stand-ups at the beginning of each meeting, sprint retrospectives, sprint planning, sprint review). I reviewed the answers to ThinkOS and Head First C with my team members to make sure I was ready and really quickly reviewed the chapters that we worked on. I felts fairly well-prepared for the review, but I'm worried that I won't retain this information moving forward, especially if we don't talk about it again. Hopefully, ThinkOS and Head First C will continue to touch back on earlier lessons, but I am also planning on reviewing my old answers to questions and such when I am preparing for my future sprint reviews.

As far as how I am located in the project, I feel like I am facing the issue of connecting my theoretical knowledge with actual implementation of the project. I think this partially stems from getting theoretical help from Allen in class and trying to merge that with the implementations that I have seen and the example code that I have examined. I do still think that we are in a good place, but there is still some uncertainty. I think that I have been making consistent progress on the project, which is helped by regular team meetings and check ins.


## Links to Head First C exercises

During this sprint I read chapters 1-2.5, but only completed exercises 1 and 2 fully. I will be attending Sophie's office hours tonight to answer questions on exercise 2.5.

[Head First C exercises 1,2, and kind of 2.5](/homework)

## Written answers to reading questions from Think OS

This sprint, I have read ThinkOS chapters 1-3 and completed all associated reading questions.
[ThinkOS Chapters 1-3 questions answered](/reading_questions/thinkos.md)

## Exam question(s) and solutions

### Question:

Why is it usful to have virtual pages from several processes that map to the same physical page? How is it done?

### Answer:

When several processes need to have access to the same memory, it makes more sense to have each vitural page access the same space in physical memory than store the memory in each process's virtual page. They do so by drawing from the read-only portion of physical memory so they cannot overwrite any necessary information, as shown in this [lovely lecture picture](https://cba15ec5-a-62cb3a1a-s-sites.googlegroups.com/site/softsys17/lectures/lecture-06/virtual_memory.png?attachauth=ANoY7coeGyo5TG_qmdV6kk8nAyzgDKEhtj2rZzepcJynyvlf2RyQsQ7IlWrgdvdVRfXnEGN5Dt3i54OjTedSjKg7TAJ9htQOrST9Zz7d2lzXqBWlPRVQOaVIKaDz5-ExrF7mgJDk3fz0wOxKGswtPX0MIot9SNkagHCxijMKJtoBZFPz7IxB6vO-XUt-8PF3r7bR9bNpBK_No2kIDqqUOp5ItQPtwkztd5EgnfK9Xkb-10W-tSgyTASpuqYa1S6gcImqhCVT7pq1&attredirects=0)


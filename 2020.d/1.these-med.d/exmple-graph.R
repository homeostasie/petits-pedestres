
d <- data.frame(pre = data.fgsm3$pre, post = data.fgsm3$post)
ggpaired(d, cond1 = "pre", cond2 = "post",
    fill = "condition", palette = "jco")
    
wdata = data.frame(
   test = groupes.FGSM3.PP,
   notes = c(data.fgsm3$pre, post = data.fgsm3$post))
head(wdata, 4)


gghistogram(wdata, x = "notes",
   add = "mean", rug = TRUE,
   color = "test", fill = "test",
   palette = c("#00AFBB", "#E7B800"))


ggboxplot(wdata, x = "test", y = "notes",
                color = "test", palette =c("#00AFBB", "#E7B800", "#FC4E07"),
                add = "jitter", shape = "test")


ggviolin(wdata, x = "test", y = "notes", fill = "test",
         palette = c("#00AFBB", "#E7B800", "#FC4E07"),
         add = "boxplot", add.params = list(fill = "white"))



ggbarplot(wdata, x = c(1:(nb.fgsm3*2)), y = "notes",
          fill = "test",               # change fill color by cyl
          color = "white",            # Set bar border colors to white
          palette = "jco",            # jco journal color palett. see ?ggpar
          sort.val = "desc",          # Sort the value in dscending order
          sort.by.groups = FALSE,     # Don't sort inside each group
          x.text.angle = 90           # Rotate vertically x axis texts
          )


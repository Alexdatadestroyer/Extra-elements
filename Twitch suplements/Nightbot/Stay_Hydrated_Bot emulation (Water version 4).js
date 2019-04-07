/* Code adapted from Water Version 3 created by Anonymous User and posted on Github. This is Water Version 4 which works better on Nightbot as long as the command field uses the
   code below and the Timer gets set 5 to 5 minutes and 2 lines of chat to work. Still unstable and has some bugs but it works well majority of times if the chat gets movimented.
   
   Text language below is on Brazilian Portuguese but you can change whatever language that you want before implementing the code on a command on Nightbot.
   
   After created the command, set the Timer already said before to call this the command created setting an alias for it. This needs to be made because Timers don't accept variables.
*/

$(eval var T = Date.now() - Date.parse('$(twitch $(channel) "{{uptimeAt}}")'); var H = Math.trunc (T / 3600000); var M = Math.trunc ((T % 3600000) / 60000); (H > 0) ? (M >= 0 && M <= 4) ? "/me $(twitch $(channel) "{{displayName}}") está em live em torno de " + H + " hora(s) e " + M + " minuto(s). A essa altura, tu já deveria ter consumido pelo menos uns " + (120*H + 2*M) + "mL de água para uma boa hidratação! DrinkPurple " : " " : " ")

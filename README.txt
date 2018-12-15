# OOP_PaintForKids_Ph2
# Our WorkFlow :-
 1- Figure Objects
 2- Action Classes
  2.1 - Figure Actions --> Amr
  2.2 - Copy/Cut/Paste --> Ebrahim
  2.3 - Save/Load --> Attia
  2.4 - Play Mode --> Attia/Ebrahim
  2.5 - Color Mode --> Sido
 3- ApplicationManager
 4- Finalizing ( Burning on CD )


# WorkLoop:-
 void phase2()
 {
  do
  {
   while ( ! Workflow.getCurrentTask().isWorking() ) {
          WorkFlow.getCurrentTask().excute();
          App.test();    
   }
   App.git().commit_remote();
  } while ( Workflow.getCurrentTask().isLast() );
 }

# 6.4.2 Stakeholder Needs and Requirements Definition process 
## 1. Prepare for Stakeholder Needs and Requirements Definition 
### a. Identify the stakeholders who have an interest in the software system throughout its lifecycle.
#### i) a
#### ii) There aren’t specific references to shareholders in the book, there are only users.  According to the book, Interaction Designers should “make sense of the world of the user, although they are no substitute for conversation with real people.”  Therefore, I think in XP, essentially Beck would want an Interaction Designer to talk to the users, who become the stakeholders, which includes our client.  
#### iii) Luckily, for this project, the stakeholders were already identified for us by our client: game developers.  
### b. Define the stakeholder needs and requirements definition strategy.
#### i) b
#### ii) Beck always says there is “no substitute for conversation with real people”.  Essentially, the definition strategy should always be to have lengthy conversations with the stakeholders, updating requirements and needs as necessary.
#### iii) Our strategy is we have extensive conversations with the client.
### c. Identify and plan for the necessary enabling systems or services needed to support stakeholder needs and requirements definition. 
#### i) h
#### ii) Beck says to “invest in the design of the system every day”.  I think planning for those systems or services would be done incrementally when they would need to be planned in a certain story, instead of planning it all ahead of time.
#### iii) Our client identified the systems we need for this project: OpenXR and Raylib.  We have spent time to start to understand these systems separately in order to start planning for integrating them into our system.
### d. Obtain or acquire access to the enabling systems or services to be used
#### i) h
#### ii) Beck says there should only be “one code stream”.  This means you should put all services into one code stream in order so use them adequately.
#### iii) We have put Raylib into our repo, and our currently working on putting OpenXR into our repo, keeping our code cleanly one stream.
## 2. Define Stakeholder Needs
### a. Define context of use within the concept of operations and the preliminary life cycle concepts. 
#### i) b
#### ii) Beck doesn’t believe in using documentation, so while this should be defined generally, that should be by just coding inside the context of operations instead of explaining what that context should be.
#### iii) This is something the client has already provided and communicated with us, using an example of a different library: Raylib, that we are then editing to be usable in VR.
### b. Identify Stakeholder Needs
#### i) d
#### ii) Beck wants “the customers pick a week’s worth of stories to implement this week”, which means the stakeholder can easily communicate their needs for the week through the stories provided.
#### iii) We have a weekly meeting where we suggest tasks to the client, and he approves or suggests different tasks, and communicates any needs or constraints related to those tasks.
### c. Prioritize and down-select needs
#### i) e
#### ii) Beck talks about communicating with the users in the book a lot.  When you’re prioritizing needs, XP states that you should do that with the user, so that the users can approve of the overall needs.
#### iii) The client for the most part had their requirements and needs laid out for us in our project in a document, but as we have gotten to more specific needs, we have simply waited to be able to ask questions when we get to it, using incremental design.
### d. Define the stakeholder needs and rationale
#### i) d
#### ii) One of the main values of XP is “communication” which means the customer communicates their needs and rationale through talking to the team.
#### iii) We have a weekly meeting where we suggest tasks to the client, and he approves or suggests different tasks, and communicates any needs or constraints related to those tasks, and why the requirements or constraints exist.
## 3. Develop the operational concept and other life cycle concepts
### a. Define a representative set of scenarios to identify the required capabilities that correspond to anticipated operational and other life cycle concepts. 
#### i) b
#### ii) Beck wants the only deliverables to be “code and tests”.  So instead of scenarios in regular English, we are supposed to come up with tests based on those scenarios.
#### iii) We will be doing manual testing, so we will be writing out the short scenarios as “tests”.  For example, when running the example program for OpenXR, you should see a rectangle on the Quest.  
### b. Identify the factors affecting interactions between users and the system
#### i) c
#### ii) Beck always says there is “no substitute for conversation with real people”.  Therefore, Beck’s view is that in order to figure out the factors affecting those interactions is to talk to the users themselves.
#### iii) We have weekly meetings with the client, where he has provided us with the factors affecting interactions between users and the system.  
## 4. Transform stakeholder needs into stakeholder requirements.
### a. Identify the constraints on a system solution
#### i) c
#### ii) Beck doesn’t believe in large requirements documents, since he says “The clearer the quarterly cycle becomes at expressing the business priorities, the slimmer the requirement document needs to be.”  With incremental design, there is less of a need to document these requirements, instead relying on code and tests.
#### iii) We have some documentation on requirements that are from the client, but we have not ourselves created requirements documentation, instead creating things incrementally with lots of communication with the client.
### b. Identify the stakeholder requirements and functions that relate to critical quality characteristics, such as assurance, safety, security, environment, or health
#### i) f
#### ii) Beck values “immediate feedback” which means that stakeholders should communicate their requirements with immediate feedback to the team.
#### iii) There aren’t any relations to safety, security, environment or health in our project, so it isn’t really necessary for our project.  
### c. Define stakeholder requirements, consistent with life cycle concepts, scenarios, interactions, constraints, and critical quality characteristics.
#### i) b
#### ii) Beck emphasizes “Test-First Programming” where “before you write code, write a test that expresses your intention.” This approach ensures requirements are defined through executable test that capture scenarios and constraints. 
#### iii) Project implementation: We defined our requirements through test cases and user stories that are reviewed with the client during weekly meetings, ensuring alignment with their guidance. 
## 5. Analyze stakeholder requirements.
### a. Analyze the complete set of stakeholder requirements. 
#### i) i
#### ii) XP approach: Beck believes in incrementally developing the system, therefore not analyzing all of the requirements at once, saying “Early estimation is a key difference between stories and other requirements practices.”  This allows for more efficiency.
#### iii) Project approach: While we do have a general goal, we don’t have a complete set of requirements, instead we try to come up with a list of tasks to do with the client, and get the requirements for those tasks, not the whole system.
### b. Define critical performance measures that enable the assessment of technical achievement.
#### i) f
#### ii) XP approach: Beck emphasizes measuring progress through working software and passing tests rather than abstract metrics. 
#### iii) Project approach: Our critical measures include successful rendering in VR, through proper integration between OpenXR and Raylib, which we validate through testing. 
### c. Feed back the analyzed requirements to applicable stakeholders to validate that their	 needs and expectations have been adequately captured and expressed
#### i) g
#### ii) XP approach: Planning in XP involves continuous feedback between business and development. 
#### iii) We validate requirements through weekly demos or progress updates with our client(Steve), getting immediate feedback on whether OpenXR/Raylib/basic C-game development is up to his standards. 
### d. Resolve stakeholder requirements issues. 
#### i) g
#### ii) Beck says that “real conversations” are what drives XP, so in order to resolve any stakeholder requirements issues, you have to have real conversations with the stakeholders and figure out how to compromise.
#### iii) We have had talks about requirements issues like having libraries in C and C++ with the client, and resolved them.
## 6. Manage the stakeholder needs and requirements definition.
### a. Obtain explicit agreement with designated stakeholders on the stakeholder requirements. 
#### i) g
#### ii) One of the values in XP is “communication” which includes talking to stakeholders about their requirements.  He values “immediate feedback”, which can only be gotten in a real conversation, where stakeholders are a valuable participation of creating these requirements.
#### iii) We have our weekly meetings with the client where the client approves of our tasks for the week, or we discuss it until we can come up with what the client as the stakeholder is happy with.
### b. Maintain traceability of stakeholder needs and requirements
#### i) i
#### ii) Beck says “Conversation allows for clarification, immediate feedback, brainstorming together, and other things you can’t do with a document.”  This shows that Beck doesn’t believe in keeping stakeholder needs and requirements in documentation, but instead traces them back in conversation.
#### iii) Our team, like Beck, does not create documentation, but instead everything can be traced back to communication, especially with our client.  There isn’t as much need for traceability of needs to requirements when everything is based on conversations of what needs to be done incrementally.
### c.  Provide key artifacts and information items that have been selected for baselines. 
#### i) b
#### ii) XP approach: Beck believes in “the code is the design” and emphasizes working software over comprehensive documentation. However, he acknowledges the need for some baseline artifacts through test cases. 
#### iii) Our project approach: Our baseline artifacts include our codebase and weekly meeting notes that capture key decisions and requirements. 
# 6.4.4 Architecture Definition Process
## 1. Prepare for architecture definition
### a. Review pertinent information and identify key drivers of the architecture
#### i) a
#### ii) Beck recognizes that real customers are crucial in planning out projects, including determining key architectural drivers: “Make people whose lives and business are affected by your system part of the team. Visionary customers can be part of quarterly and weekly planning.”
#### iii) We will work with our client directly when determining the key architectural drivers, which is especially valuable because he is a highly technical client who has worked in industry.
### b. Identify stakeholder concerns
#### i) a
#### ii) Beck believes that the best way to identify stakeholder concerns is to just talk to the stakeholders themselves: “The point of customer involvement is to reduce wasted effort by putting the people with the needs in direct contact with the people who can fill those needs.”
#### iii) We will talk to our stakeholders (us and Steve) to determine what the concerns are
### c. Define the Architecture Definition roadmap, approach, and strategy
#### i) h
#### ii) Beck likely believes that Architecture Definition should be a done a little bit at a time, incrementally: “Design done close to when it is used is more efficient”
#### iii) We shall define the roadmap with this in mind, and plan to continuously develop our Architecture Definition.
### d. Define architecture evaluation criteria based on stakeholder concerns and key requirements
#### i) a
#### ii) Once again, Beck’s stance on this would likely be driven by his view of real-customer involvement: “No customer at all, or a “proxy” for a real customer, leads to waste as you develop features that aren’t used, specify tests that don’t reflect the real acceptance criteria…”
#### iii) We will therefore involve Steve directly with this and work with him to define our criteria based on what the key drivers are.
### e. Identify and plan for the necessary enabling systems or services needed to support the Architecture Definition process
#### i) j
#### ii) Beck believes in incremental deployment in addition to incremental design, so he would likely advise us to integrate these into our plan gradually rather than all at once: “Find a little piece of functionality or a limited data set you can handle right away. Deploy it.”
#### iii) We plan to first integrate one of the two backend dependencies, then the other, in keeping with the Beck philosophy.
### f. Obtain or acquire access to the enabling systems or services to be used
#### i) j
#### ii) Beck talks about contracts in the context of negotiating contracts with clients rather than enabling systems, but we believe he’d likely have the same philosophy in this case: “Reduce risk by signing a sequence of short contracts instead of one long one.” Throughout XP, he consistently has talked about splitting things up into much smaller parts. Hence, we think he’d want us to obtain a short license/contract/subscription to the service if needed, experiment with it, and if it fits, agree to a longer period of use.
#### iii) We’ve already obtained access to our dependencies. However, we’re still in the midst of setting them up in the context of our project. We approached this by first accessing them individually and ensuring that they build and work as intended and are now integrating them together to ensure they are compatible.
## 2. Develop architecture viewpoints
### a. Select, adapt, or develop viewpoints and model kinds based on stakeholder concerns
#### i) b
#### ii) Beck, as always, puts stakeholders in the drivers’ seat for items like this one: “If this is the kind of customer who encounters problems six months before the rest of the market, making the system they want can put you ahead of your competition.” By directly interfacing with the stakeholders and adapting the viewpoints based on their needs, we can ensure best practices and directly meeting stakeholder desires.
#### iii) Since we’re already working closely with our client, this should be relatively easy. One thing we’ve already been doing is demoing some code, feature, or mini project to our client every other week so he can observe progress and see if our visions are following the same path.
### b. Establish or identify potential architecture framework(s) to be used in developing models and views
#### i) g
#### ii) Beck says the following about architects’ role in a project: “Rather than divide and conquer, an XP team conquers and divides. First a small team writes a small system. Then they find the natural fracture lines and divide the system into relatively independent parts for expansion. The architects help choose the most appropriate fracture lines and then follow the system as a whole, keeping the big picture in mind as the groups focus on their smaller section.” From this, it sounds like identifying frameworks should be done as the project progresses, and it should follow a natural progression by identifying patterns that can be filled by such frameworks. 
#### iii) In our project, while it is not an architectural framework per se, we noted that we should be able to fulfill a large part of our responsibility of this project by using the adapter pattern to our advantage, allowing us to easily integrate two separate softwares while allowing for modifiability later on. This was done in keeping with Beck’s advice, as we found that fracture line naturally and followed it to expose that application of the pattern.
### c. Capture rationale for selection of framework(s), viewpoints and model kinds
#### i) g
#### ii) Beck likely believes that this is something that should be done by writing good code and by writing tests that align with these selections: “Maintain only the code and the tests as permanent artifacts.” Because there are no other artifacts, the history of these decisions must lie in these two areas, along with the technique of using “social mechanisms to keep alive important history of the project.” Effectively, Beck is saying that between code/tests and word of mouth, decisions should be able to be reproduced at a later point.
#### iii) Our project doesn’t quite fulfill the Beck vision of using only code and tests as we’re keeping meeting minutes and design documents to capture our decisions.
### d. Select or develop supporting modeling techniques and tools
#### i) d
#### ii) This also falls under Beck’s incremental design philosophy: “” He would want us to develop the tools and techniques a small amount at a time.
#### iii) We are developing our model of the OpenXR component piece by piece to ensure that we have a working version of it that we can integrate into Raylib.
## 3. Develop models and views of candidate architectures
### a. Define the software system context and boundaries in terms of interfaces and interactions with external entities
#### i) c
#### ii) The internal product should first be defined, then external interactions can be continuously worked in: “Integrate and test changes after no more than a couple of hours.” Beck talks about integration in the context of an internal build, but we feel that his philosophy would also apply to external entities.
#### iii) We have defined our boundaries as not exceeding Raylib’s and fully utilizing OpenXR’s API so that we do not have to interact with graphics internals too much.
### b. Identify architectural entities and relationships between entities that address key stakeholder concerns and critical software system requirements
#### i) k
#### ii) Beck reminds us to keep it simple: “XP teams prefer simple solutions where possible.” These relationships should be as simple as possible to ensure that we are not overcomplicating a solution.
#### iii) We have designed our architecture to be as simple as possible while still allowing us to deploy a MVP. 
### c. Allocate concepts, properties, characteristics, behaviors, functions, or constraints that are significant to architecture decisions of the software system to architectural entities
#### i) e
#### ii) Beck believes that there is only one constraint at a time: “The Theory of Constraints says that in any system there is one constraint at a time (occasionally two).” Therefore, we would want to identify it and allocate it to an entity, then repeat.
#### iii) We allocated our behaviors to each of the Raylib and OpenXR entities according to what made the most sense after talking as a team.
### d. Select, adapt, or develop models of the candidate architectures of the software system
#### i) d
#### ii) Beck believes that these models should be developed near the time the code is written, and continuously change as the code changes: “Invest in the design of the system every day.”
#### iii) We created our model at the beginning of the quarter and have often changes
### e. Compose views from the models in accordance with identified viewpoints to express how the architecture addresses stakeholder concerns and meets stakeholder and system/software requirements
#### i) k
#### ii) Beck believes that these views should be composed at the time that a stakeholder needs them, and thrown away afterward: “Generate other documents from the code and tests.”
#### iii) We will write our views based on our current architecture depending on when Steve asks for them.
### f. Harmonize the architecture models and views with each other
#### i) d
#### ii) Because there is only a single code base, Beck would likely say that this is already done: “There is only one code stream. You can develop in a temporary branch, but never let it live longer than a few hours.”
#### iii) Since we allowed feature branches, we push each feature into main as soon as it is complete. That way, the model and views are generally harmonized.
## 4. Relate the architecture to design
### a. Identify software system elements that relate to architectural entities and the nature of these relationships
#### i) f
#### ii) This should be easy to do if XP has been followed, in Beck’s eyes: “XP teams work hard to create conditions under which the cost of changing the software doesn’t rise catastrophically.” As long as incremental design has been followed, each element that was added should map easily to architectural entities.
#### iii) In our case, the OpenXR component of our product relates directly to the external architectural entity that we defined for it, as we call in functions via its API.
### b. Define the interfaces and interactions among the software system elements and external entities
#### i) j
#### ii) XP Approach: Beck advocates for “incremental design,” where you build out the system’s design over time, so software elements and interactions should only be defined as needed. He also advocates for code and tests to be the only documentation in order to clearly indicate the system’s functionality.
#### iii) We will develop tests for all of the expected interactions of our software with external entities to verify when our code is functioning as intended.
### c. Partition, align and allocate requirements to architectural entities and system elements
#### i) k
#### ii) Beck mentions using “Test-First Programming” to establish the goals of software when it is being written and make sure it ties back to requirements. Beck also recommends assigning code to write in stories that tie directly into given requirements, which will make every coding session start from a group of requirements and establishing tests to ensure they are followed.
#### iii) We will develop our stories based on requirements and write the tests for the stories at the start of a coding session, which will allow us to stay in line with the requirements and have guaranteed examples of the requirements working.
### d. Map software system elements and architectural entities to design characteristics
#### i) i
#### ii) Beck recommends utilizing “Incremental Design” to ensure that the design of the system meets the needs of the system and ensure cohesion of designs to the current design. If the design is not changing rapidly, it is unlikely for the codebase to expand to a field that is not directly mappable to the design characteristics.
#### iii) We will ensure that all our members understand our design and any changes that we make to it, in order to ensure that we are following our specified design characteristics. For example, for interactions with exterior libraries, we will standardize any API calls to ensure we are not breaking our design with excessive coupling.
### e. Define principles for the software system design and evolution
#### i) c
#### ii) Beck recommends using “incremental design” to keep the design of the software from being expanded too quickly and keep the software focused around the key functionality needed by the current functionality.
#### iii) We will utilize incremental design for the evolution of our software by only updating the design to reflect needed changes as they arise instead of making large plans that may end up changing. At each story, we will review the current design to establish the minimal number of design changes to implement the feature and do so.
## 5. Assess architecture candidates
### a. Assess each candidate architecture against constraints and requirements
#### i) g
#### ii) Beck recommends using “test-first programming” to ensure that any code that gets written will run under a precise set of expected conditions. The tests will be built from given constraints and requirements to ensure that if there is a point when the code is not meeting the requirements, the coders know about it and can move to address it as soon as possible.
#### iii) We will use test-first programming to ensure that we are meeting all requirements. Whenever a set program expectation is given, we will work to develop a most likely asynchronous, but possibly synchronous, test that will verify if that requirement is being met. We will run our tests whenever we commit code to the codebase in the form of a PR to ensure that we can fix any errors before they enter our codebase.
### b. Assess each candidate architecture against stakeholder concerns using evaluation criteria
#### i) g
#### ii) Beck recommends writing “stories” based on information from the stakeholders that establish the developmental aims of the programmers. Coupled with incremental deployment, there is a steady stream of input from the stakeholders so that any concerns they have get addressed.
#### iii) We will check with the stakeholder any time we are choosing between different architectures to ensure we are picking the architecture that best meets their needs. We have already begun to do so by verifying the languages that our codebase will support, by checking with our client and ensuring that he wants it all written in Native C for optimal integrations.
### c. Select the preferred architecture(s) and capture key decisions and rationale
#### i) h
#### ii) Beck recommends using “Code and Tests” to serve as the only sources of documentation in a codebase. Any decisions being made in the codebase in terms of architecture or design should be implemented in the codebase and tests, so there is little to no need for additional documentation to describe other rationale.
#### iii) We will make a short design document in case we have any crucial decisions to now about when using our codebase to make it more accessible to everyday users. The goal of our project is to build a system that can be used and implemented by anyone, so we will need documentation to show people how to get it to work.
### d. Establish the architecture baseline of the selected architecture
#### i) f
#### ii) Beck recommends using a “single codebase” when implementing a project to ensure that any branches or features that are being implemented quickly become a part of the baseline architecture.
#### iii) We will limit the amount of time that we have feature branches outside of the main development branch to ensure that all of our code is in line with our core design. Any code on the main branch will be functional and we will be able to easily add or remove features as needed by staying close to the base architecture.
## 6. Manage the selected architecture
### a. Formalize the architecture governance approach and specify governance-related roles and responsibilities, accountabilities, and authorities related to design, quality, security, and safety
#### i) h
#### ii) Beck recommends using “pair programming” to ensure accountability behind any code. By working as a team, it is less likely for code to appear that only one person understands or for any simple mistakes to occur.
#### iii) We will use pair programming frequently with each other and our client to ensure code is functional and we all have a good understanding of the codebase. We also have assigned roles to ourselves to oversee particular aspects of the project so we know who to direct our and others questions to for any particular part of the project.
### b. Obtain explicit acceptance of the architecture by stakeholders
#### i) a
#### ii) Beck recommends using “incremental deployment” to keep the stakeholders informed of the current state of the project and minimize the amount of work done when a concern arises. By frequently updating the outward facing side of the project, if an issue occurs, you will be ablet o locate exactly what area may have caused the area by its time of arrisal and the recent updates.
#### iii) We will develop a deployment schedule once we have code that we are ready to distribute so that any stakeholders can interact with it and inform us of bugs that they encounter. Our goal is to create a project that is accessible to all, so with frequent updates, we will be ablet o receive as much user input as possible and improve any areas that need it as issues occur.
### c. Maintain concordance and completeness of the architectural entities and their architectural characteristics
#### i) c
#### ii) Beck mentions using “Test-First Programming” to establish the limits of functionality as we are programming and maintain the intended functionality of software.
#### iii) We will write tests for different pieces of the architecture before we write software to ensure that the proposed piece of the architecture functions as intended and only within the limits of our tests.
### d. Organize, assess and control evolution of the architecture models and views to help ensure that architectural intent is met and the architectural vision and key concepts are correctly implemented
#### i) h
#### ii) Beck recommends using “incremental design” to keep the design of the software from being expanded too quickly and keep the software focused around the key functionality needed by the current codebase. Any needs that arise over time can be addressed in the incremental design by expanding it when they occur, such as the need for new views.
#### iii) We will utilize incremental design for the evolution of our software by only updating the design to reflect needed changes as they arise instead of making large plans that may end up changing. At each story, we will review the current design to establish the minimal number of design changes to implement the feature and do so. By focusing on tests as well, we will ensure that our design is functional and intent is being met before moving on to new stages of development.
### e. Maintain the architecture definition and evaluation strategy
#### i) c
#### ii) Beck recommends using “incremental design” to keep the design of the software from being expanded too quickly and keep the software focused around the key functionality needed by the current functionality.
#### iii) We will utilize incremental design for the evolution of our software by only updating the design to reflect needed changes as they arise instead of making large plans that may end up changing. At each story, we will review the current design to establish the minimal number of design changes to implement the feature and do so. By updating only small areas of the design at a time, we ensure the current architecture definition and evaluation strategy will be consistent across design changes and codebase development.
### f. Maintain traceability of the architecture
#### i) k
#### ii) Beck recommends using “test-first programming” to ensure that any code that gets written will run under a precise set of expected conditions. Since tests should be developed directly from stories, this ensures traceability of the architecture back to the stakeholders’ requirements and concerns.
#### iii) We will develop our stories based on requirements and write the tests for the stories at the start of a coding session, which will allow us to stay in line with the requirements and have guaranteed examples of the requirements working. By maintaining a connection between stories and tests, we are able to have a traceable link between any functionality and client requirements.
### g. Provide key artifacts and information items that have been selected for baselines
#### i) k
#### ii) Beck recommends using “Code and Tests” to serve as the only sources of documentation in a codebase. Any decisions being made in the codebase in terms of architecture or design should be implemented in the codebase and tests, so there is little to no need for additional documentation to describe other rationale.
#### iii) Any artifacts or information items can be generated from the code and tests of our program (with the exception of some possible design guidelines for users). Since the generated artifacts will be partially on the tests, which ensure our baseline requirements, we will have a clear path of information from our architecture to the baselines of the project.
# 6.4.5 Design Definition Process
## 1. Prepare for Software System Design Definition
### a. Define the design definition strategy, consistent with the selected life cycle model and anticipated design artifacts
#### i) Outcome: c
#### ii) XP Approach: "Simple Design" is key - Beck advocates for the simplest design that could possibly work, using the four rules: runs all tests, no duplicated code, states everything once and only once, and has the fewest possible classes and methods.
#### iii) Project Approach: Our strategy focuses on incremental development with weekly iterations, prioritizing working VR functionality first, following the simplicity principles of XP.
### b. Select and prioritize design principles and design characteristics
#### i) Outcome: a
#### ii) XP approach: Beck emphasizes design emerges from refactoring rather than upfront planning.
#### iii) Project approach: We prioritize modular design for easy testing, clear separation between OpenXR and Raylib components, and maintainable code structure.
### c. Identify and plan for the necessary enabling systems or services needed to support design definition
#### i) c
#### ii) Beck says to “invest in the design of the system every day”.  Planning the design should be done incrementally, possibly using ADD like in CSSE 477.  The enabling systems need to be taken into account when creating the initial design, and in every incrementation these enabling systems need to be considered.
#### iii) Our client identified the systems we need for this project: OpenXR and Raylib.  We have spent time to start to understand these systems separately in order to start planning for integrating them into our system.  We also have started to take that into account in the design, by discussing how things should be built, if they should be in C or C++, and other design considerations. 
### d. Obtain or acquire access to the enabling systems or services to be used
#### i) Outcome: g
#### ii) XP approach: Beck advocates for having "the whole team together" with all necessary tools and resources readily available. ‘Have everything you need’ is a key principle.
#### iii) Project approach: We've set up development environments with necessary SDKs, obtained Quest 3 hardware for testing, and established access to both OpenXR and Raylib codebases.
## 2. Establish Designs Related to Each Software System Element
### a. Transform architectural and design characteristics into the design of software system elements
#### i) Outcome: a
#### ii) XP approach: Through "Continuous Integration" and "Small Releases", XP transforms high-level design into working code incrementally. Not XP, but as Steve Jobs states: "Design is not just what it looks like and feels like. Design is how it works."
#### iii) Project approach: We're implementing the VR wrapper functionality piece by piece, transforming Raylib's 2D/3D capabilities into VR-compatible elements.
### b. Define and prepare or obtain the necessary design enablers
#### i) Outcome: c
#### ii) XP approach: "Test-First Programming" serves as a design enabler in XP. Beck believes that tests give you confidence that the simple thing really works.
#### iii) Project approach: We've established testing frameworks for both C and C++ components, and created sample VR applications to validate our design approach.
### c. Examine design alternatives and feasibility of implementation
#### i) Outcome: e
#### ii) XP approach: When you have a technical problem, solve it by first writing the simplest possible program that could shed light on the problem.
#### iii) Project approach: We explored different approaches for integrating OpenXR with Raylib, testing feasibility through small prototype implementations.
### d. Refine or define the interfaces among the software system elements and with external entities
#### i) Outcome: d
#### ii) XP approach: Beck emphasizes clean, non-redundant interfaces that are continuously refactored.
#### iii) Project approach: We're defining clear interfaces between Raylib and OpenXR components, ensuring clean separation of concerns and maintainable integration points.
### e. Establish the design elements
#### i) Outcome: f
#### ii) XP approach: XP builds design elements through "Small Releases" and "Incremental Design".
#### iii) Project approach: We're establishing core VR wrapper components, rendering pipelines, and input handling systems incrementally based on weekly priorities.
## 3. Access Alternatives for Obtaining Software System Elements
### a. Determine technologies required for each element composing the software system
#### i) Outcome: a
#### ii) XP approach: XP emphasizes choosing technologies that enable fast feedback and continuous integration.
#### iii) Project Implementation: We've selected C/C++ for compatibility with both libraries, OpenXR for VR support, and Raylib for graphics rendering.
### b. Identify candidate alternatives for the software system elements
#### i) Outcome: e
#### ii) XP approach: XP suggests exploring alternatives through spikes but keeping things simple. 
#### iii) Project approach: We evaluated different approaches like direct OpenGL integration vs. Raylib, and native vs. wrapper implementations.
### c. Access each candidate alternative against criteria developed from expected design characteristics and element requirements
#### i) Outcome: e
#### ii) XP approach: Beck advocates for making decisions based on concrete feedback:
#### iii) Project approach: We evaluated alternatives based on ease of integration, performance impact, and maintainability through prototype implementations.
## 4. Manage the Design
### a. Capture the design and rationale
#### i) Outcome: f
#### ii) XP approach: Beck emphasizes that well-written code with tests serves as the primary design documentation.
#### iii) Project approach: We maintain our design decisions through clear code structure, comprehensive tests, and weekly meeting notes capturing key rationales.
### b. Establish traceability between the detailed design elements, the system/software requirements, and the architectural entities
#### i) Outcome: h
#### ii) XP approach: XP maintains traceability through continuous integration and automated tests. "Tests are documentation" - Beck emphasizes that tests show how the system should work.
#### iii) Project approach: We maintain traceability through Git commits linked to tasks, test cases mapping to requirements, and regular client reviews.
### c. Determine the status of the software system and element design
#### i) Outcome: a
#### ii) XP approach: XP determines status through working software and passing tests.
#### iii) Project approach: We track status through working functionality demonstrated in weekly meetings, test coverage, and successful VR implementations.
### d. Provide key artifacts and information items that have been selected for baselines
#### i) Outcome: f
#### ii) Beck says that “Any artifacts contributing to these two sources of value are themselves valuable. Everything else is waste.”
#### iii) Our only artifacts other than code and tests are our meeting minutes. These can be useful to us, but we are not storing other non-code artifacts.

# Commande de délétion
RM=rm
# Flags de délétion
RMFLAGS=-rf


# Répertoires de bibliothèques
LIBDIR?=

# Commande écho
ECHO=@echo

#Nom de l'executable
PROGNAME=lutin

# Dossiers d'include pero
INCDIR=inc

# Dossier d'include externes
EXTINCDIR?=

# Dossier sources
SRCDIR=src

# Dossier objets
OBJDIR=.obj

# Dossier où sont mises les dépendances
DEPDIR=.dep
df=$(@D)/$(*F)

ALLSRC=$(shell find $(SRCDIR) -type f -name *.cpp)
SRC=$(ALLSRC:$(SRCDIR)/%=%)
INC=$(shell find $(INCDIR) -type f \( -name *.hpp -o -name *.h -o -name *.tpp \) | sed -e "s/$(INCDIR)\///")

OBJ=$(SRC:.cpp=.o)

CLEAR=clean

MAKEDEPEND = g++ $(addprefix -I, $(EXTINCDIR)) -I$(INCDIR) -o $(DEPDIR)/$(df:$(OBJDIR)/%=%).d -std=c++11 -MM $< #Pour calculer les dépendances

#Compilateur
CC=g++
#Options du compilateur
CCFLAGS+=-Wall -fpermissive -Wextra -Woverloaded-virtual -c -std=c++11 -I$(INCDIR) $(addprefix -I, $(EXTINCDIR)) $(addprefix -l, $(LIB)) 

EL=g++ #Éditeur de liens
ELFLAGS=

#dossier pour les tests
TESTDIR=../test
TESTCMD=./mktest.sh
TESTLINK=$(TESTDIR)/lut
TEST=test

ifeq ($(OS),Windows_NT)
    ELFLAGS+= -largp
endif

DEBUG?=FALSE

MAP?=FALSE

PROF?=FALSE

ifneq ($(DEBUG),FALSE)
    CCFLAGS+= -g
    ELFLAGS+= -g
endif

ifneq ($(MAP),FALSE)
    CCFLAGS+= -DMAP
endif

ifneq ($(PROF),FALSE)
    CCFLAGS+= -pg
    ELFLAGS+= -pg
endif

.PHONY: $(CLEAR)
.PHONY: $(TEST)
.PHONY: ALL

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp 
	@mkdir -p $(dir $(DEPDIR)/$(df:$(OBJDIR)/%=%));
	@mkdir -p $(@D);
	@$(MAKEDEPEND); \
		cp $(DEPDIR)/$(df:$(OBJDIR)/%=%).d $(DEPDIR)/$(df:$(OBJDIR)/%=%).P;\
		sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	            -e '/^$$/ d' -e 's/$$/ :/' < $(DEPDIR)/$(df:$(OBJDIR)/%=%).d >> $(DEPDIR)/$(df:$(OBJDIR)/%=%).P;\
		    sed -i '1s/^/$(subst /,\/,$(@D))\//' $(DEPDIR)/$(df:$(OBJDIR)/%=%).P;
		@rm -f $(DEPDIR)/$(df:$(OBJDIR)/%=%).d
	$(ECHO) "Compilation de $<"
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -o $@ $<

ALL: $(PROGNAME)

$(TESTLINK): $(PROGNAME)
	ln -fs `pwd`/$(PROGNAME) $(TESTLINK)

$(TEST): $(TESTLINK)
	$(ECHO) "Batterie de test lancée"
	cd $(TESTDIR); \
		$(TESTCMD)
	
$(PROGNAME): $(addprefix $(OBJDIR)/, $(OBJ)) 
	$(ECHO) "Fabrication de l'executable"
	$(EL) -o $(PROGNAME) $(addprefix $(OBJDIR)/, $(OBJ)) $(ELFLAGS) $(addprefix -l, $(LIB)) 

#Fichiers de dépendance
-include $(SRC:%.cpp=$(DEPDIR)/%.P)

$(CLEAR):
	$(RM) $(RMFLAGS) $(OBJDIR)/* $(DEPDIR)/* $(PROGNAME)
